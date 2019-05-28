/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** BuffedSystem.cpp
*/
#include "BuffedSystem.hpp"

ECS::BuffedSystem::BuffedSystem(ECS::ECSCore &core):
    System("Buffed", core)
{}

void ECS::BuffedSystem::updateEntity(ECS::Entity &entity)
{}