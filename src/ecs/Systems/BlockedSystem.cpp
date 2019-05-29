/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** BlockedSytem.cpp
*/
#include "BlockedSystem.hpp"
#include "../Components/CollisionComponent.hpp"
#include "../Components/PositionComponent.hpp"
#include "../Components/MovableComponent.hpp"
#include "../../config.hpp"

ECS::BlockedSytem::BlockedSytem(ECS::ECSCore &core):
    System("Block", core)
{
    this->_dependencies = {"Collision", "Position"};
}

void ECS::BlockedSytem::updateEntity(ECS::Entity &entity)
{
    auto &entity_hitbox = reinterpret_cast<CollisionComponent &>(entity.getComponentByName("Collision"));

    for (auto &wall : entity_hitbox.entitiesCollided) {
        auto &entity_pos = reinterpret_cast<PositionComponent &>(entity.getComponentByName("Position"));
        auto &entity_mov = reinterpret_cast<MovableComponent &>(entity.getComponentByName("Movable"));
        auto &wall_hitbox = reinterpret_cast<CollisionComponent &>(wall->getComponentByName("Collision"));
        if (wall_hitbox.hardness <= entity_hitbox.passthough)
            continue;
        int relative_x = static_cast<int>(entity_pos.pos.x) % TILESIZE;
        int relative_y = static_cast<int>(entity_pos.pos.y) % TILESIZE;
        while ((relative_x >= 0 && relative_x < TILESIZE) || (relative_y >= 0 && relative_y < TILESIZE)) {
            if (entity_mov.dir & UP) {
                entity_pos.pos.y += 1;
                relative_y += 1;
            }
            if (entity_mov.dir & DOWN) {
                entity_pos.pos.y -= 1;
                relative_y -= 1;
            }
            if (entity_mov.dir & LEFT) {
                entity_pos.pos.x += 1;
                relative_x += 1;
            }
            if (entity_mov.dir & RIGHT) {
                entity_pos.pos.x -= 1;
                relative_x -= 1;
            }
        }
    }
}