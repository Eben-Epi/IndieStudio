/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** ExplodeSystem.cpp
*/

#include "ExplodeSystem.hpp"
#include "../Components/ExplodeComponent.hpp"
#include "../Components/HealthComponent.hpp"
#include "../Components/PositionComponent.hpp"
#include "../ECSCore.hpp"
#include "../../config.hpp"
#include "../Components/ColliderComponent.hpp"
#include "../Components/DisplayableComponent.hpp"

ECS::ExplodeSystem::ExplodeSystem(ECS::ECSCore &core) :
    System("Explode", core)
{
    this->_dependencies = {"Health", "Position"};
}

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

    if (exc.exploded)
        entity.destroy();

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

        efHPos.pos = posAndSize[0];
        dc.screen.setPosition(dc.entityId, efHPos.pos.x, efHPos.pos.y);
        efHPos.size = posAndSize[1];
        efVPos.pos = posAndSize[2];
        dcv.screen.setPosition(dcv.entityId, efVPos.pos.x, efVPos.pos.y);
        efVPos.size = posAndSize[3];
        exc.exploded = true;
    }
}