/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** HealthSystem.cpp
*/
#include "HealthSystem.hpp"

ECS::HealthSystem::HealthSystem(ECS::ECSCore &core) :
	System("Health", core)
{
}

void ECS::HealthSystem::updateEntity(ECS::Entity &entity)
{
}