/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** DroppedBonusBomb.cpp
*/

#include "DroppedBonusBomb.hpp"
#include "../Components/HealthComponent.hpp"
#include "../Components/DisplayableComponent.hpp"
#include "../Components/ColliderComponent.hpp"
#include "../Components/PositionComponent.hpp"
#include "../../config.hpp"
#include "../Components/PowerUpComponent.hpp"
#include "../Components/PickableComponent.hpp"
#include "../Components/PowerUpPickedComponent.hpp"

ECS::DroppedBonusBomb::DroppedBonusBomb(unsigned id, const Ressources &ressources) :
    Entity(id, "DroppedBonusBomb", {
        new HealthComponent(1),
        new DisplayableComponent("DroppedBonusBomb", ressources),
        new ColliderComponent(0),
        new PositionComponent({0, 0}, {TILESIZE, TILESIZE}),
        new PowerUpComponent({{"Bomb", 1}}),
        new PickableComponent(),
        new PowerUpPickedComponent()
    })
{
}