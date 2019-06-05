/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** UltimeSystem.cpp
*/
#include "UltimeSystem.hpp"
#include "../Components/UltimeComponent.hpp"
#include "../../config.hpp"

ECS::UltimeSystem::UltimeSystem(ECS::ECSCore &core):
    System("Ultime", core)
{}

void ECS::UltimeSystem::updateEntity(ECS::Entity &entity)
{
    auto &uc = reinterpret_cast<UltimeComponent &>(entity.getComponentByName("Ultime"));

    uc.charge += 60 / FRAME_RATE;
}