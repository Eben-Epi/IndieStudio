/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** BlockedSystem.cpp
*/
#include <cmath>
#include "BlockedSystem.hpp"
#include "../Components/CollisionComponent.hpp"
#include "../Components/PositionComponent.hpp"
#include "../Components/MovableComponent.hpp"
#include "../../config.hpp"
#include "../Components/ColliderComponent.hpp"

ECS::BlockedSystem::BlockedSystem(ECS::ECSCore &core):
    System("Block", core)
{
    this->_dependencies = {"Collision", "Position"};
}

void ECS::BlockedSystem::updateEntity(ECS::Entity &entity)
{
    auto &entity_hitbox = reinterpret_cast<CollisionComponent &>(entity.getComponentByName("Collision"));

    for (auto &wall : entity_hitbox.entitiesCollided) {
        auto &entity_pos = reinterpret_cast<PositionComponent &>(entity.getComponentByName("Position"));
        auto &entity_mov = reinterpret_cast<MovableComponent &>(entity.getComponentByName("Movable"));
        auto &wall_hitbox = reinterpret_cast<ColliderComponent &>(wall->getComponentByName("Collider"));

        if (wall_hitbox.hardness <= entity_hitbox.passThrough)
            continue;

        double relative_x = fmod(entity_pos.pos.x, TILESIZE);
        double relative_y = fmod(entity_pos.pos.y, TILESIZE);
        while ((relative_x >= 0 && relative_x <= TILESIZE && entity_mov.dir & (RIGHT | LEFT))
            || (relative_y >= 0 && relative_y <= TILESIZE && entity_mov.dir & (UP | DOWN))) {
            printf("[DEBUG] Collision at: x: %f y: %f rx: %f ry: %f TILESET: %d d: %d\n", entity_pos.pos.x, entity_pos.pos.y, relative_x, relative_y, TILESIZE, entity_mov.dir);
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