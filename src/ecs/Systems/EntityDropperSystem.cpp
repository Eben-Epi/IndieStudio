/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** ItemDropperSystem.cpp
*/

#include "EntityDropperSystem.hpp"
#include "../Components/PositionComponent.hpp"
#include "../Components/EntityDropperComponent.hpp"
#include "../ECSCore.hpp"
#include "../Components/HealthComponent.hpp"

ECS::EntityDropperSystem::EntityDropperSystem(ECS::ECSCore &core) :
    System("EntityDropper", core)
{
    this->_dependencies = {"Position", "Health"};
}

void ECS::EntityDropperSystem::updateEntity(ECS::Entity &entity)
{
    auto &posComp = reinterpret_cast<PositionComponent &>(entity.getComponentByName("Position"));
    auto &hthComp = reinterpret_cast<HealthComponent &>(entity.getComponentByName("Health"));
    auto &itemDropper = reinterpret_cast<EntityDropperComponent &>(entity.getComponentByName("ItemDropper"));

    if (!itemDropper.items.empty()) {
        Entity &newEntity = this->_core.makeEntity(itemDropper.items[0]);
        reinterpret_cast<PositionComponent &>(newEntity.getComponentByName("Position")).pos = posComp.pos;
    }

}