/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** PositionSystem.cpp
*/
#include "PositionSystem.hpp"

ECS::PositionSystem::PositionSystem(ECS::ECSCore &core):
    System("Position", core)
{}

void ECS::PositionSystem::updateEntity(ECS::Entity &entity)
{}