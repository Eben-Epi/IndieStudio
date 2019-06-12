/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** CurseOnPickSystem.cpp
*/

#include <random>
#include "CurseOnPickSystem.hpp"
#include "../components/PickableComponent.hpp"
#include "../components/CurseComponent.hpp"
#include "../../config.hpp"
#include "../components/CurseOnPickComponent.hpp"

ECS::CurseOnPickSystem::CurseOnPickSystem(ECS::ECSCore &core):
    System("CurseOnPick", core)
{
    this->_dependencies = {"Pickable"};
}

void ECS::CurseOnPickSystem::updateEntity(ECS::Entity &entity)
{
    auto &self = reinterpret_cast<CurseOnPickComponent &>(entity.getComponentByName("CurseOnPick"));
    auto &pc = reinterpret_cast<PickableComponent &>(entity.getComponentByName("Pickable"));

    if (pc.pickedBy == nullptr)
        return;

    auto &cc = reinterpret_cast<CurseComponent &>(pc.pickedBy->getComponentByName("Curse"));
    std::random_device random_dev;
    auto curse = static_cast<CurseComponent::CurseEffect >(random_dev() % (CurseComponent::_NUMBER_OF_CURSE - 1) + 1);
    cc.giveCurse(curse, 10 * FRAME_RATE, true);
    entity.destroy();
}