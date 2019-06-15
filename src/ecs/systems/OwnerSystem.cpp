/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** OwnerSystem.cpp
*/
#include "OwnerSystem.hpp"

ECS::OwnerSystem::OwnerSystem(ECS::ECSCore &core):
    System("Owner", core)
{}

void ECS::OwnerSystem::updateEntity(ECS::Entity &entity)
{}