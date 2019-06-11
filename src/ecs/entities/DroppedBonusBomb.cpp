/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** DroppedBonusBomb.cpp
*/

#include "DroppedBonusBomb.hpp"
#include "../components/HealthComponent.hpp"
#include "../components/DisplayableComponent.hpp"
#include "../components/ColliderComponent.hpp"
#include "../components/PositionComponent.hpp"
#include "../../config.hpp"
#include "../components/PowerUpComponent.hpp"
#include "../components/PickableComponent.hpp"
#include "../components/PowerUpPickedComponent.hpp"
#include "../components/MortalComponent.hpp"

ECS::DroppedBonusBomb::DroppedBonusBomb(unsigned id, Ressources &ressources) :
    Entity(id, "DroppedBonusBomb", {
        new HealthComponent(1),
        new DisplayableComponent("DroppedBonusBomb", ressources),
        new ColliderComponent(0),
        new MortalComponent(),
        new PositionComponent({0, 0}, {TILESIZE, TILESIZE}),
        new PowerUpComponent(ressources.soundSystem, {{"Bomb", 1}}),
        new PickableComponent(),
        new PowerUpPickedComponent()
    })
{
}