/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** BlockedSystem.cpp
*/
#include <cmath>
#include <algorithm>
#include "../Exceptions.hpp"
#include "BlockedSystem.hpp"
#include "../components/CollisionComponent.hpp"
#include "../components/PositionComponent.hpp"
#include "../components/MovableComponent.hpp"
#include "../../config.hpp"
#include "../components/ColliderComponent.hpp"
#include "../components/BlockedComponent.hpp"

ECS::BlockedSystem::BlockedSystem(ECS::ECSCore &core):
    System("Blocked", core)
{
    this->_dependencies = {"Collision", "Position"};
}

void ECS::BlockedSystem::updateEntity(ECS::Entity &entity)
{
    auto &bc = reinterpret_cast<BlockedComponent &>(entity.getComponentByName("Blocked"));
    auto &entity_hitbox = reinterpret_cast<CollisionComponent &>(entity.getComponentByName("Collision"));

    for (auto &i : bc.whitelistId)
        if (std::find(entity_hitbox.entitiesCollided.begin(), entity_hitbox.entitiesCollided.end(), i) == entity_hitbox.entitiesCollided.end())
            bc.whitelistId.erase(std::remove(bc.whitelistId.begin(), bc.whitelistId.end(), i), bc.whitelistId.end());

    for (auto &wall : entity_hitbox.entitiesCollided) {
        auto &entity_pos = reinterpret_cast<PositionComponent &>(entity.getComponentByName("Position"));
        auto &entity_mov = reinterpret_cast<MovableComponent &>(entity.getComponentByName("Movable"));
        auto &wall_hitbox = reinterpret_cast<ColliderComponent &>(wall->getComponentByName("Collider"));
        auto &wall_pos = reinterpret_cast<PositionComponent &>(wall->getComponentByName("Position"));

        if (wall_hitbox.hardness <= entity_hitbox.passThrough || std::find(bc.whitelistId.begin(), bc.whitelistId.end(), wall) != bc.whitelistId.end())
            continue;

        double relative_x = entity_pos.pos.x - wall_pos.pos.x;
        double relative_y = entity_pos.pos.y - wall_pos.pos.y;
        if (relative_x < -28.f || relative_x >= 32.f || relative_y < -28.f || relative_y >= 32.f)
            continue;

        /* block_id represent which zone of the block the player collide, block_id use value like that (in hexa)
         *  +-+-+-+-+
         *  |0|1|2|3|    0 and 5 : UP LEFT
         *  +-+-+-+-+    1 and 2 : UP
         *  |4|5|6|7|    3 and 6 : UP RIGHT
         *  +-+-+-+-+    4 and 8 : LEFT
         *  |8|9|A|B|    7 and B : RIGHT
         *  +-+-+-+-+    9 and C : DOWN LEFT
         *  |C|D|E|F|    D and E : DOWN
         *  +-+-+-+-+    A and F : DOWN RIGHT*/

        char block_id = (static_cast<int>((4*(relative_y - -PLAYERSIZE) / (TILESIZE - -PLAYERSIZE))) << 2)
                        + (static_cast<int>((4*(relative_x - -PLAYERSIZE) / (TILESIZE - -PLAYERSIZE))));
        switch (block_id) {
        case 0:
        case 5: // UP LEFT
            entity_pos.pos.y -= MIN(relative_x + PLAYERSIZE, relative_y + PLAYERSIZE) + .1; // rup
            entity_pos.pos.x -= MIN(relative_x + PLAYERSIZE, relative_y + PLAYERSIZE) + .1; // rleft
            break;
        case 1:
        case 2: // UP
            entity_pos.pos.y = wall_pos.pos.y - PLAYERSIZE - .1;
            break;
        case 3:
        case 6: // UP RIGHT
            entity_pos.pos.y -= MIN(relative_x + PLAYERSIZE, relative_y + PLAYERSIZE) + .1; // rup
            entity_pos.pos.x += MIN(TILESIZE - relative_x, TILESIZE - relative_y) + .1; // rright
            break;
        case 4:
        case 8: // LEFT
            entity_pos.pos.x = wall_pos.pos.x - wall_pos.size.x - .1;
            break;
        case 7:
        case 11: // RIGHT
            entity_pos.pos.x = wall_pos.pos.x + wall_pos.size.x + .1;
            break;
        case 9:
        case 12: // DOWN LEFT
            entity_pos.pos.y += MIN(TILESIZE - relative_x, TILESIZE - relative_y) + .1; // rdown
            entity_pos.pos.x -= MIN(relative_x + PLAYERSIZE, relative_y + PLAYERSIZE) + .1; // rleft
            break;
        case 13:
        case 14: // DOWN
            entity_pos.pos.y = wall_pos.pos.y + wall_pos.size.y + .1;
            break;
        case 10:
        case 15: // DOWN RIGHT
            entity_pos.pos.y += MIN(TILESIZE - relative_x, TILESIZE - relative_y) + .1; // rdown
            entity_pos.pos.x += MIN(TILESIZE - relative_x, TILESIZE - relative_y) + .1; // rright
            break;
        }
        entity_mov.speed = 0;
    }
}