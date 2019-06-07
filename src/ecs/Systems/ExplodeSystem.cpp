/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** ExplodeSystem.cpp
*/

#include "ExplodeSystem.hpp"
#include "../ECSCore.hpp"
#include "../Components/ExplodeComponent.hpp"
#include "../Components/HealthComponent.hpp"
#include "../Components/PositionComponent.hpp"
#include "../Components/ColliderComponent.hpp"
#include "../Components/DisplayableComponent.hpp"
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

    if (exc.exploded) {
        entity.destroy();
        return;
    }
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
    exc.exploded = true;
}

/*
ECS::ExplosionObstructionLocation ECS::ExplodeSystem::isOnExplosionWay(std::vector<ECS::Vector2<double>> &posAndSize, ECS::Point &pos, ECS::PointF BombPos)
{
    if (pos.y <= posAndSize[0].y && pos.y + TILESIZE > posAndSize[0].y + posAndSize[1].y && pos.x >= posAndSize[0].x && pos.x <= BombPos.x) {
        return (ECS::WEST_OBS);
    }
    if (pos.y <= posAndSize[0].y && pos.y + TILESIZE > posAndSize[0].y + posAndSize[1].y && pos.x >= BombPos.x && pos.x < (posAndSize[0].x + posAndSize[1].x))
        return (ECS::EAST_OBS);
    if (pos.x <= posAndSize[2].x && pos.x + TILESIZE > posAndSize[2].x + posAndSize[3].x && pos.y >= posAndSize[2].y && pos.y <= BombPos.y)
        return (ECS::NORTH_OBS);
    if (pos.x <= posAndSize[2].x && pos.x + TILESIZE > posAndSize[2].x + posAndSize[3].x && pos.y >= BombPos.y && pos.y < (posAndSize[2].y + posAndSize[3].y))
        return (ECS::SOUTH_OBS);
    return (ECS::NO_OBS);
}

void ECS::ExplodeSystem::updateEntity(ECS::Entity &entity)
{
    auto &hc = reinterpret_cast<HealthComponent &>(entity.getComponentByName("Health"));
    auto &pc = reinterpret_cast<PositionComponent &>(entity.getComponentByName("Position"));
    auto &exc = reinterpret_cast<ExplodeComponent &>(entity.getComponentByName("Explode"));

    std::vector<ECS::Vector2<double>> posAndSize = {
        {1 + pc.pos.x - (TILESIZE * exc.range), pc.pos.y},
        {(double)(TILESIZE * (exc.range * 2 + 1)), (double)pc.size.y},
        {1 + pc.pos.x, pc.pos.y - (TILESIZE * exc.range)},
        {(double)pc.size.x, (double)(TILESIZE * (exc.range * 2 + 1))}
    };
    const std::vector<Entity *> &hardnessEntities = this->_core.getEntitiesByComponent("Collision");

    if (hc.health == 0) {
        for (Entity *e : hardnessEntities) {
            PositionComponent &ePC = reinterpret_cast<PositionComponent &>(e->getComponentByName("Position"));
            ColliderComponent &eCC = reinterpret_cast<ColliderComponent &>(e->getComponentByName("Collider"));

            if (e->getId() != entity.getId()) {
                ECS::ExplosionObstructionLocation location = isOnExplosionWay(posAndSize, ePC.pos, pc.pos);

                switch (location) {
                    case WEST_OBS:
                        // strength > hardness : goes through and deal damages, strength == hardness, s'arrête devant le mur avec dégâts, strength < hardness s'arrête devant le mur sans dégâts
                        if (eCC.hardness == exc.strength && posAndSize[0].x < ePC.pos.x) {
                            posAndSize[1].x = posAndSize[1].x - (ePC.pos.x - posAndSize[0].x);
                            posAndSize[0].x = ePC.pos.x;
                        } else if (eCC.hardness > exc.strength && posAndSize[0].x < ePC.pos.x + TILESIZE) {
                            posAndSize[1].x = posAndSize[1].x - ((ePC.pos.x + TILESIZE) - posAndSize[0].x);
                            posAndSize[0].x = ePC.pos.x + TILESIZE;
                        }
                        break;
                    case EAST_OBS:
                        if (eCC.hardness == exc.strength && posAndSize[0].x + posAndSize[1].x - TILESIZE > ePC.pos.x)
                            posAndSize[1].x =
                                posAndSize[1].x - ((posAndSize[0].x + posAndSize[1].x - TILESIZE) - ePC.pos.x);
                        else if (eCC.hardness > exc.strength && posAndSize[0].x + posAndSize[1].x > ePC.pos.x)
                            posAndSize[1].x = posAndSize[1].x - ((posAndSize[0].x + posAndSize[1].x) - ePC.pos.x);
                        break;
                    case NORTH_OBS:
                        if (eCC.hardness == exc.strength && posAndSize[2].y < ePC.pos.y) {
                            posAndSize[3].y = posAndSize[3].y - (ePC.pos.y - posAndSize[2].y);
                            posAndSize[2].y = ePC.pos.y;
                        } else if (eCC.hardness > exc.strength && posAndSize[2].y < ePC.pos.y + TILESIZE) {
                            posAndSize[3].y = posAndSize[3].y - ((ePC.pos.y + TILESIZE) - posAndSize[2].y);
                            posAndSize[2].y = ePC.pos.y + TILESIZE;
                        }
                        break;
                    case SOUTH_OBS:
                        if (eCC.hardness == exc.strength && posAndSize[2].y + posAndSize[3].y - TILESIZE > ePC.pos.y)
                            posAndSize[3].y =
                                posAndSize[3].y - ((posAndSize[2].y + posAndSize[3].y - TILESIZE) - ePC.pos.y);
                        else if (eCC.hardness > exc.strength && posAndSize[2].y + posAndSize[3].y > ePC.pos.y)
                            posAndSize[3].y = posAndSize[3].y - ((posAndSize[2].y + posAndSize[3].y) - ePC.pos.y);
                        break;
                    default:
                        break;
                }
            }
        }

        Entity &horizontalEF = this->_core.makeEntity("ExplosionFrame");
        Entity &verticalEF = this->_core.makeEntity("ExplosionFrame");
        PositionComponent &efHPos = reinterpret_cast<ECS::PositionComponent &>(horizontalEF.getComponentByName("Position"));
        auto &dc = reinterpret_cast<ECS::DisplayableComponent &>(horizontalEF.getComponentByName("Displayable"));
        PositionComponent &efVPos = reinterpret_cast<ECS::PositionComponent &>(verticalEF.getComponentByName("Position"));
        auto &dcv = reinterpret_cast<ECS::DisplayableComponent &>(horizontalEF.getComponentByName("Displayable"));

        exc.soundSystem.playSound("explode");
        efHPos.pos = posAndSize[0];
        dc.screen.setPosition(dc.entityId, efHPos.pos.x, efHPos.pos.y);
        efHPos.size = posAndSize[1];
        efVPos.pos = posAndSize[2];
        dcv.screen.setPosition(dcv.entityId, efVPos.pos.x, efVPos.pos.y);
        efVPos.size = posAndSize[3];
        entity.destroy();
    }
}*/