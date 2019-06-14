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
    return (BETWEEN(e.pos.x, x, e.pos.x + e.size.x) && BETWEEN(e.pos.y, y, e.pos.y + e.size.y));
}

static int get_first_collided(ECS::PositionComponent &pc, unsigned range, std::vector<ECS::Entity *> &entities, bool r, bool v, unsigned strength)
{
    for (int i = 1; i <= range; i++)
        for (ECS::Entity *e : entities) {
            auto &ip = reinterpret_cast<ECS::PositionComponent &>(e->getComponentByName("Position"));
            auto &ic = reinterpret_cast<ECS::ColliderComponent &>(e->getComponentByName("Collider"));
            if (ic.hardness < strength)
                continue;
            if (entities_collied(pc.pos.x + (TILESIZE / 2 + TILESIZE * (v ? 0 : (r ? -i : i))), pc.pos.y + (TILESIZE / 2 + TILESIZE * (v ? (r ? -i : i) : 0)), ip)) {
                if (e->hasComponent("Health"))
                    reinterpret_cast<ECS::HealthComponent &>(e->getComponentByName("Health")).takeDamage();
                return i - 1;
            }
        }
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

    if (hc.health != 0)
        return;

    auto &pc = reinterpret_cast<PositionComponent &>(entity.getComponentByName("Position"));
    auto &exc = reinterpret_cast<ExplodeComponent &>(entity.getComponentByName("Explode"));
    int min_x, max_x, min_y, max_y;

    std::vector<Entity *> entities = this->_core.getEntitiesByComponent("Collider");

    pc.pos.x = (static_cast<int>(pc.pos.x) + TILESIZE / 2) / TILESIZE * TILESIZE;
    pc.pos.y = (static_cast<int>(pc.pos.y) + TILESIZE / 2) / TILESIZE * TILESIZE;

    min_x = static_cast<int>(pc.pos.x) - get_first_collided(pc, exc.range, entities, true, false, exc.strength) * TILESIZE;
    max_x = static_cast<int>(pc.pos.x) + (get_first_collided(pc, exc.range, entities, false, false, exc.strength) + 1) * TILESIZE;
    min_y = static_cast<int>(pc.pos.y) - get_first_collided(pc, exc.range, entities, true, true, exc.strength) * TILESIZE;
    max_y = static_cast<int>(pc.pos.y) + (get_first_collided(pc, exc.range, entities, false, true, exc.strength) + 1) * TILESIZE;

    Entity &horizontalEF = this->_core.makeEntity("ExplosionFrame");
    Entity &verticalEF = this->_core.makeEntity("ExplosionFrame");
    PositionComponent &efHPos = reinterpret_cast<ECS::PositionComponent &>(horizontalEF.getComponentByName("Position"));
    PositionComponent &efVPos = reinterpret_cast<ECS::PositionComponent &>(verticalEF.getComponentByName("Position"));

    efHPos.pos.x = min_x + 1;
    efHPos.pos.y = pc.pos.y + 1;
    efHPos.size.x = static_cast<unsigned>(max_x - min_x) - 2;
    efVPos.pos.x = pc.pos.x + 1;
    efVPos.pos.y = min_y + 1;
    efVPos.size.y = static_cast<unsigned>(max_y - min_y) - 2;
    exc.soundSystem.playSound("explode");
    entity.destroy();
}
