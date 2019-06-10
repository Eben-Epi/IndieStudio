/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** EphemeralSystem.cpp
*/
#include "EphemeralSystem.hpp"
#include "../components/HealthComponent.hpp"
#include "../components/EphemeralComponent.hpp"

ECS::EphemeralSystem::EphemeralSystem(ECS::ECSCore &core) :
	System("Ephemeral", core)
{
}

void ECS::EphemeralSystem::updateEntity(ECS::Entity &entity)
{
    auto &ec = reinterpret_cast<EphemeralComponent &>(entity.getComponentByName("Ephemeral"));
    auto &hc = reinterpret_cast<HealthComponent &>(entity.getComponentByName("Health"));

    if (ec.timeLeft > 0)
        ec.timeLeft -= 1;
    if (!ec.timeLeft)
        hc.health = 0;

}