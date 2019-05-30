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
#include "../Components/EphemeralComponent.hpp"
#include "../ECSCore.hpp"
#include "../../config.hpp"

ECS::ExplodeSystem::ExplodeSystem(ECS::ECSCore &core) :
    System("Explode", core)
{
    this->_dependencies = {"Health", "Position", "Ephemeral"};
}

ECS::ExplosionObstructionLocation isOnExplosionWay(std::vector<ECS::Vector2<double>> &posAndSize, ECS::Point &pos, ECS::PointF BombPos)
{
    if (pos.y == posAndSize[0].y && pos.x >= posAndSize[0].x && pos.x <= BombPos.x)
        return (ECS::WEST_OBS);
    if (pos.y == posAndSize[0].y && pos.x >= BombPos.x && pos.x < (posAndSize[0].x + posAndSize[1].x))
        return (ECS::EAST_OBS);
    if (pos.x == posAndSize[2].x && pos.y >= posAndSize[2].y && pos.y <= BombPos.y)
        return (ECS::NORTH_OBS);
    if (pos.x == posAndSize[2].x && pos.y >= BombPos.y && pos.y < (posAndSize[2].y + posAndSize[3].y))
        return (ECS::SOUTH_OBS);
    return (ECS::NO_OBS);
}

void ECS::ExplodeSystem::updateEntity(ECS::Entity &entity)
{
    auto &hc = reinterpret_cast<HealthComponent &>(entity.getComponentByName("Health"));
    auto &pc = reinterpret_cast<PositionComponent &>(entity.getComponentByName("Position"));
    auto &ec = reinterpret_cast<EphemeralComponent &>(entity.getComponentByName("Ephemeral"));
    auto &exc = reinterpret_cast<ExplodeComponent &>(entity.getComponentByName("Explode"));
    std::vector<ECS::Vector2<double>> posAndSize = {
        {pc.pos.x - (TILESIZE * exc.range), pc.pos.y},
        {(double)(TILESIZE * (exc.range * 2 + 1)), (double)pc.size.y},
        {pc.pos.x, pc.pos.y - (TILESIZE * exc.range)},
        {(double)pc.size.x, (double)(TILESIZE * (exc.range * 2 + 1))}
    };
    ECS::ExplosionObstructionLocation location;

    if (hc.health == 0 && entity.getName() == "Bomb") {
        const std::vector<Entity *> &entitiesByName = this->_core.getEntitiesByComponent("Position");
        for (Entity *e : entitiesByName) {
            if ((e->getName() == "Wall" || e->getName() == "Brick") && (location = isOnExplosionWay(posAndSize, reinterpret_cast<PositionComponent &>(e->getComponentByName("Position")).pos, pc.pos)) != NO_OBS) {
                switch (location) {
                    case WEST_OBS:
                        if (e->getName() == "Brick")
                            posAndSize[0] = {reinterpret_cast<PositionComponent &>(e->getComponentByName("Position")).pos.x, pc.pos.y};
                        else
                            posAndSize[0] = {reinterpret_cast<PositionComponent &>(e->getComponentByName("Position")).pos.x + TILESIZE, pc.pos.y};
                        //TODO EAST, SOUTH, NORTH OBSTRUCITONS
                    default:
                        break;
                }
            }
        }

        //TODO explode according to the terrain : walls cannot be passed through, bricks die and explosion pass through one,

        PositionComponent &efHPos = reinterpret_cast<ECS::PositionComponent &>(this->_core.makeEntity("ExplosionFrame").getComponentByName("Position"));
        efHPos.pos = {pc.pos.x - (TILESIZE * exc.range), pc.pos.y};
        efHPos.size = {(TILESIZE * (exc.range * 2 + 1)), pc.size.y};
        PositionComponent &efVPos = reinterpret_cast<ECS::PositionComponent &>(this->_core.makeEntity("ExplosionFrame").getComponentByName("Position"));
        efVPos.pos = {pc.pos.x, pc.pos.y - (TILESIZE * exc.range)};
        efVPos.size = {pc.size.x, (TILESIZE * (exc.range * 2 + 1))};
    }
}