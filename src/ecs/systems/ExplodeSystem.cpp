/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** ExplodeSystem.cpp
*/

#include "ExplodeSystem.hpp"
#include "../ECSCore.hpp"
#include "../components/ExplodeComponent.hpp"
#include "../components/HealthComponent.hpp"
#include "../components/PositionComponent.hpp"
#include "../components/ColliderComponent.hpp"
#include "../components/DisplayableComponent.hpp"
#include "../../config.hpp"

static inline bool entities_collied(double x, double y, ECS::PositionComponent &e)
{
    // printf("Entity Collided(%f, %f, e_pos: %f:%f, e_size: %d:%d)\n", x, y, e.pos.x, e.pos.y, e.size.x, e.size.y);
    // printf("Condition %d && %d\n", BETWEEN(e.pos.x, x, e.pos.x + e.size.x), BETWEEN(e.pos.y, y, e.pos.y + e.size.y));
    return (BETWEEN(e.pos.x, x, e.pos.x + e.size.x) && BETWEEN(e.pos.y, y, e.pos.y + e.size.y));
}

static int get_first_collided(ECS::PositionComponent &pc, unsigned range, std::vector<ECS::Entity *> &entities, bool r, bool v)
{
    for (int i = 1; i <= range; i++)
        for (ECS::Entity *e : entities) {
            auto &ip = reinterpret_cast<ECS::PositionComponent &>(e->getComponentByName("Position"));
            auto &ic = reinterpret_cast<ECS::ColliderComponent &>(e->getComponentByName("Collider"));
            if (!ic.hardness)
                continue;
            if (entities_collied(pc.pos.x + (TILESIZE / 2 + TILESIZE * (v ? 0 : (r ? -i : i))), pc.pos.y + (TILESIZE / 2 + TILESIZE * (v ? (r ? -i : i) : 0)), ip)) {
                // printf("check collision in %f:%f\n", pc.pos.x + (TILESIZE / 2 + TILESIZE * (v ? 0 : (r ? -i : i))), pc.pos.y + (TILESIZE / 2 + TILESIZE * (v ? (r ? -i : i) : 0)));
                // printf("Collided with %s (%f;%f) when i = %d (r: %d v: %d)\n", e->getName().c_str(), ip.pos.x, ip.pos.y, i, r, v);
                if (e->hasComponent("Health"))
                    reinterpret_cast<ECS::HealthComponent &>(e->getComponentByName("Health")).takeDamage();
                return i - 1;
            }
        }
    // printf("returned %d (range) for r: %d v: %d\n", range, r, v);
    return range; // if no collide, return the max range of the bomb
}

ECS::ExplodeSystem::ExplodeSystem(ECS::ECSCore &core) :
        System("Explode", core)
{
    this->_dependencies = {"Health", "Position"};
}

void ECS::ExplodeSystem::updateEntity(ECS::Entity &entity)
{
    auto &hc = reinterpret_cast<HealthComponent &>(entity.getComponentByName("Health"));
    auto &pc = reinterpret_cast<PositionComponent &>(entity.getComponentByName("Position"));
    auto &exc = reinterpret_cast<ExplodeComponent &>(entity.getComponentByName("Explode"));

    if (hc.health != 0)
        return;

    Vector2<int> explose_size = {};
    int min_x, max_x, min_y, max_y;
    int i;
    std::vector<Entity *> entities = this->_core.getEntitiesByComponent("Collider");

    min_x = static_cast<int>(pc.pos.x) - get_first_collided(pc, exc.range, entities, true, false) * TILESIZE;
    max_x = static_cast<int>(pc.pos.x) + (get_first_collided(pc, exc.range, entities, false, false) + 1) * TILESIZE;
    min_y = static_cast<int>(pc.pos.y) - get_first_collided(pc, exc.range, entities, true, true) * TILESIZE;
    max_y = static_cast<int>(pc.pos.y) + (get_first_collided(pc, exc.range, entities, false, true) + 1) * TILESIZE;
    printf("Explosion:\nx : %d - %d\ny: %d - %d\n--------------\n", min_x, max_x, min_y, max_y);

    Entity &horizontalEF = this->_core.makeEntity("ExplosionFrame");
    Entity &verticalEF = this->_core.makeEntity("ExplosionFrame");
    PositionComponent &efHPos = reinterpret_cast<ECS::PositionComponent &>(horizontalEF.getComponentByName("Position"));
    PositionComponent &efVPos = reinterpret_cast<ECS::PositionComponent &>(verticalEF.getComponentByName("Position"));

    efHPos.pos.x = min_x;
    efHPos.pos.y = min_y;
    efHPos.size.x = static_cast<unsigned>(max_x - min_x);
    efHPos.size.y = static_cast<unsigned>(max_y - min_y);
    exc.soundSystem.playSound("explode");
    entity.destroy();
}
