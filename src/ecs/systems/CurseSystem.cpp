/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** CurseSystem.cpp
*/
#include "CurseSystem.hpp"
#include "../Components/CurseComponent.hpp"

ECS::CurseSystem::CurseSystem(ECS::ECSCore &core):
    System("Curse", core)
{}

void ECS::CurseSystem::updateEntity(ECS::Entity &entity)
{
    auto &cc = reinterpret_cast<CurseComponent&>(entity.getComponentByName("Curse"));

    if (cc.timeLeft > 0)
        cc.timeLeft -= 1;
    else if (cc.timeLeft == 0) {
        cc.effect = CurseComponent::NONE;
        cc.timeLeft = -1;
    }
}