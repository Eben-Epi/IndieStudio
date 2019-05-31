/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** OnCollisionDamageDealerSystem.cpp
*/

#include "OnCollisionDamageDealerSystem.hpp"

ECS::OnCollisionDamageDealerSystem::OnCollisionDamageDealerSystem(ECS::ECSCore &core):
    System("Movable", core)
{
    this->_dependencies = {"Position", "Collision"};
}

void ECS::OnCollisionDamageDealerSystem::updateEntity(ECS::Entity &entity)
{
    //TODO DealDamage Colliding with objects
}