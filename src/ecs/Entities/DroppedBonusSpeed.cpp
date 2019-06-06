/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** DroppedBonusSpeed.cpp
*/

#include "DroppedBonusSpeed.hpp"
#include "../Components/HealthComponent.hpp"
#include "../Components/DisplayableComponent.hpp"
#include "../Components/ColliderComponent.hpp"
#include "../Components/PositionComponent.hpp"
#include "../../config.hpp"
#include "../Components/PowerUpComponent.hpp"
#include "../Components/PickableComponent.hpp"
#include "../Components/PowerUpPickedComponent.hpp"

ECS::DroppedBonusSpeed::DroppedBonusSpeed(unsigned id, const Ressources &ressources) :
    Entity(id, "DroppedBonusSpeed", {
        new HealthComponent(1),
        new DisplayableComponent("DroppedBonusSpeed", ressources),
        new ColliderComponent(0),
        new PositionComponent({0, 0}, {TILESIZE, TILESIZE}),
        new PowerUpComponent({{"Speed", 0.2}}),
        new PickableComponent(),
        new PowerUpPickedComponent()
    })
{
}