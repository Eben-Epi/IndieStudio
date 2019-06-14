/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** KickerSystem.cpp
*/

#include <algorithm>
#include "KickerSystem.hpp"
#include "../components/CollisionComponent.hpp"
#include "../components/MovableComponent.hpp"
#include "../components/BlockedComponent.hpp"
#include "../components/ColliderComponent.hpp"
#include "../components/PositionComponent.hpp"
#include "../../config.hpp"
#include "../components/KickerComponent.hpp"

ECS::KickerSystem::KickerSystem(ECS::ECSCore &core) :
    System("Kicker", core)
{
    this->_dependencies = {"Movable", "Collision", "Blocked"};
}

void ECS::KickerSystem::updateEntity(ECS::Entity &entity)
{
    auto &kick = reinterpret_cast<KickerComponent &>(entity.getComponentByName("Kicker"));

    if (!kick.canKick)
    	return;

    auto &collision = reinterpret_cast<CollisionComponent &>(entity.getComponentByName("Collision"));
    auto &bc = reinterpret_cast<BlockedComponent &>(entity.getComponentByName("Blocked"));

    for (Entity *i : collision.entitiesCollided) {
        if (i->hasComponent("Kickable") && std::find(bc.whitelistId.begin(), bc.whitelistId.end(), i) == bc.whitelistId.end()) {
            auto &i_move = reinterpret_cast<MovableComponent &>(i->getComponentByName("Movable"));
            auto &e_move = reinterpret_cast<MovableComponent &>(entity.getComponentByName("Movable"));

            i_move.dir = e_move.dir;
            i_move.maxSpeed = e_move.maxSpeed * 2;
            i_move.speed = i_move.maxSpeed;
        }
    }
}