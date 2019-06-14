/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** HealthSystem.cpp
*/
#include "HealthSystem.hpp"
#include "../components/HealthComponent.hpp"

ECS::HealthSystem::HealthSystem(ECS::ECSCore &core) :
	System("Health", core)
{
}

void ECS::HealthSystem::updateEntity(ECS::Entity &entity)
{
    auto &self = reinterpret_cast<HealthComponent &>(entity.getComponentByName("Health"));

    if (self.invunerabilityTimeLeft > 0)
        self.invunerabilityTimeLeft -= 1;
}