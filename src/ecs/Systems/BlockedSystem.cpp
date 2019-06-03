/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** BlockedSystem.cpp
*/
#include <cmath>
#include "../Exceptions.hpp"
#include "BlockedSystem.hpp"
#include "../Components/CollisionComponent.hpp"
#include "../Components/PositionComponent.hpp"
#include "../Components/MovableComponent.hpp"
#include "../../config.hpp"
#include "../Components/ColliderComponent.hpp"

ECS::BlockedSystem::BlockedSystem(ECS::ECSCore &core):
    System("Blocked", core)
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
        printf("[DEBUG] Collision at: x: %f y: %f rx: %f ry: %f TILESET: %d d: %d\n", entity_pos.pos.x, entity_pos.pos.y, relative_x, relative_y, TILESIZE, entity_mov.dir);
        char block_id = (((static_cast<int>(relative_y) + PLAYERSIZE) / ((32 + PLAYERSIZE) / 4)) << 2)
                        + (static_cast<int>(relative_x)) / FIRST_QUARTILE(0, TILESIZE);
        printf("[DEBUG] block_id = %d (%d << 2 + %d)\n", block_id, ((static_cast<int>(relative_y) + PLAYERSIZE) / ((32 + PLAYERSIZE) / 4)), (static_cast<int>(relative_x) / FIRST_QUARTILE(0, TILESIZE)));
        switch (block_id) {
        case 0:
        case 5:
            entity_pos.pos.y -= MIN(relative_x, relative_y);
            entity_pos.pos.x -= MIN(relative_x, relative_y);
            break;
        case 1:
        case 2:
            entity_pos.pos.y -= relative_y;
            entity_pos.pos.x += TILESIZE - MAX(relative_x, relative_y);
            break;
        case 3:
        case 6:
            entity_pos.pos.y -= MIN(relative_x, relative_y);
            break;
        case 4:
        case 8:
            entity_pos.pos.x -= relative_x;
            break;
        case 7:
        case 11:
            entity_pos.pos.x += TILESIZE - relative_x;
            break;
        case 9:
        case 12:
            entity_pos.pos.y += PLAYERSIZE - MAX(relative_x, relative_y);
            entity_pos.pos.x -= MIN(relative_x, relative_y);
            break;
        case 13:
        case 14:
            entity_pos.pos.y += PLAYERSIZE - relative_y;
            break;
        case 10:
        case 15:
            entity_pos.pos.y += PLAYERSIZE - MAX(relative_x, relative_y);
            entity_pos.pos.x += TILESIZE - MAX(relative_x, relative_y);
            break;
        default:
            throw ECSException("[BlockedSystem] The impossible Occurred: block_id must be >= 0 and <= 15 but it was " + std::to_string(block_id));
        }
    }
}