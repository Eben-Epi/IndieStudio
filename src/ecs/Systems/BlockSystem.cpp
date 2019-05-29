/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** BlockSystem.cpp
*/
#include "BlockSystem.hpp"
#include "../Components/CollisionComponent.hpp"
#include "../Components/PositionComponent.hpp"
#include "../Components/MovableComponent.hpp"
#include "../../config.hpp"

ECS::BlockSystem::BlockSystem(ECS::ECSCore &core):
    System("Block", core)
{
    this->_dependencies = {"Collision", "Position"};
}

void ECS::BlockSystem::updateEntity(ECS::Entity &entity)
{
    auto &cc = reinterpret_cast<CollisionComponent &>(entity.getComponentByName("Collision"));

    for (auto &i : cc.entitiesCollided) {
        if (!i->hasComponent("Movable"))
            continue;
        auto &icc = reinterpret_cast<PositionComponent &>(i->getComponentByName("Collision"));
        if (cc.hardness <= cc.passthough)
            continue;
        auto &ipc = reinterpret_cast<PositionComponent &>(i->getComponentByName("Position"));
        auto &imc = reinterpret_cast<MovableComponent &>(i->getComponentByName("Movable"));
        int relative_x = static_cast<int>(ipc.pos.x) % TILESIZE;
        int relative_y = static_cast<int>(ipc.pos.y) % TILESIZE;
        while ((relative_x >= 0 && relative_x < TILESIZE) || (relative_y >= 0 && relative_y < TILESIZE)) {
            if (imc.dir & UP) {
                ipc.pos.y += 1;
                relative_y += 1;
            }
            if (imc.dir & DOWN) {
                ipc.pos.y -= 1;
                relative_y -= 1;
            }
            if (imc.dir & LEFT) {
                ipc.pos.x += 1;
                relative_x += 1;
            }
            if (imc.dir & RIGHT) {
                ipc.pos.x -= 1;
                relative_x -= 1;
            }
        }
    }
}