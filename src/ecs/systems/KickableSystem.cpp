/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** KickableComponent.cpp
*/

#include "KickableSystem.hpp"
#include "../Components/CollisionComponent.hpp"
#include "../Components/MovableComponent.hpp"

ECS::KickableSystem::KickableSystem(ECS::ECSCore &core) :
	System("Kickable", core)
{
	this->_dependencies = {"Movable", "Collision"};
}

void ECS::KickableSystem::updateEntity(ECS::Entity &entity)
{
    auto &collision = reinterpret_cast<CollisionComponent &>(entity.getComponentByName("Collision"));

    for (Entity *i : collision.entitiesCollided) {
        if (i->hasComponent("Kicker")) {
            auto i_move = reinterpret_cast<MovableComponent &>(i->getComponentByName("Movable"));
            auto e_move = reinterpret_cast<MovableComponent &>(entity.getComponentByName("Movable"));
            e_move.dir = i_move.dir;
            e_move.speed = i_move.speed * 2;
            e_move.maxSpeed = e_move.speed;
        }
    }
}