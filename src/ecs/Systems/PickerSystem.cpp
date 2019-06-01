/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** PickerSystem.cpp
*/

#include "PickerSystem.hpp"
#include "../Components/CollisionComponent.hpp"

ECS::PickerSystem::PickerSystem(ECS::ECSCore &core):
    System("Picker", core)
{
    this->_dependencies = {"Collision"};
}

void ECS::PickerSystem::updateEntity(ECS::Entity &entity)
{
    CollisionComponent &cc = reinterpret_cast<CollisionComponent &>(entity.getComponentByName("Collision"));

    for (Entity *entityCollided : cc.entitiesCollided) {
        if (entityCollided->hasComponent("Pickable") && entityCollided->hasComponent("PowerUp"));
            //reinterpret_cast<DisplayableComponent &> entityCollided->getComponentByName("Displayable")
            //TODO set properties of the item to the player : the player must have PowerUpComponent
    }
}