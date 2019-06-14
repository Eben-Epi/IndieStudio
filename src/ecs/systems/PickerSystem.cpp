/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** PickerSystem.cpp
*/

#include "PickerSystem.hpp"
#include "../components/CollisionComponent.hpp"
#include "../components/PickableComponent.hpp"

ECS::PickerSystem::PickerSystem(ECS::ECSCore &core):
    System("Picker", core)
{
}

void ECS::PickerSystem::updateEntity(ECS::Entity &entity)
{
    CollisionComponent &cc = reinterpret_cast<CollisionComponent &>(entity.getComponentByName("Collision"));

    for (Entity *entityCollided : cc.entitiesCollided)
        if (entityCollided->hasComponent("Pickable"))
		reinterpret_cast<PickableComponent &>(entityCollided->getComponentByName("Pickable")).pickedBy = &entity;
}