/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** DroppedBonusHealth.cpp
*/


#include "DroppedBonusHealth.hpp"
#include "../Components/HealthComponent.hpp"
#include "../Components/DisplayableComponent.hpp"
#include "../Components/ColliderComponent.hpp"
#include "../Components/PositionComponent.hpp"
#include "../../config.hpp"
#include "../Components/PowerUpComponent.hpp"
#include "../Components/PickableComponent.hpp"
#include "../Components/PowerUpPickedComponent.hpp"

ECS::DroppedBonusHealth::DroppedBonusHealth(unsigned id, const Ressources &ressources) :
    Entity(id, "DroppedBonusHealth", {
        new HealthComponent(1),
        new DisplayableComponent("DroppedBonusHealth", ressources),
        new ColliderComponent(0),
        new PositionComponent({0, 0}, {TILESIZE, TILESIZE}),
        new PowerUpComponent({{"Health", 1}}),
        new PickableComponent(),
        new PowerUpPickedComponent()
    })
{
}