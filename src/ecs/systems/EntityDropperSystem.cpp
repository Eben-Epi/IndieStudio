/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** EntityDropperSystem.cpp
*/

#include "EntityDropperSystem.hpp"
#include "../components/PositionComponent.hpp"
#include "../components/EntityDropperComponent.hpp"
#include "../ECSCore.hpp"
#include "../components/HealthComponent.hpp"
#include "../components/PickableComponent.hpp"

ECS::EntityDropperSystem::EntityDropperSystem(ECS::ECSCore &core) :
    System("EntityDropper", core)
{
    this->_dependencies = {"Position", "Health"};
}

void ECS::EntityDropperSystem::updateEntity(ECS::Entity &entity)
{
    auto &posComp = reinterpret_cast<PositionComponent &>(entity.getComponentByName("Position"));
    auto &hthComp = reinterpret_cast<HealthComponent &>(entity.getComponentByName("Health"));
    auto &itemDropper = reinterpret_cast<EntityDropperComponent &>(entity.getComponentByName("EntityDropper"));

    if (!hthComp.health && !itemDropper.item.empty() && itemDropper.item != "null") {
        Entity &newEntity = this->_core.makeEntity(itemDropper.item);

        entity.destroy();
        reinterpret_cast<PositionComponent &>(newEntity.getComponentByName("Position")).pos = posComp.pos;
    } else if (!hthComp.health)
    	entity.destroy();
}