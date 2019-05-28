/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** CollisionSystem.cpp
*/

#include "CollisionSystem.hpp"

ECS::CollisionSystem::CollisionSystem(ECS::ECSCore &core):
    System("Collision", core)
{}

void ECS::CollisionSystem::updateEntity(ECS::Entity &entity)
{}