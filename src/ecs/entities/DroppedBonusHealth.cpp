/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** DroppedBonusHealth.cpp
*/


#include "DroppedBonusHealth.hpp"
#include "../components/HealthComponent.hpp"
#include "../components/DisplayableComponent.hpp"
#include "../components/ColliderComponent.hpp"
#include "../components/PositionComponent.hpp"
#include "../../config.hpp"
#include "../components/PowerUpComponent.hpp"
#include "../components/PickableComponent.hpp"
#include "../components/PowerUpPickedComponent.hpp"
#include "../components/MortalComponent.hpp"

ECS::DroppedBonusHealth::DroppedBonusHealth(unsigned id, Ressources &ressources) :
    Entity(id, "DroppedBonusHealth", {
        new HealthComponent(1),
        new DisplayableComponent("DroppedBonusHealth", ressources),
        new ColliderComponent(0),
	new MortalComponent(),
        new PositionComponent({0, 0}, {TILESIZE, TILESIZE}),
        new PowerUpComponent(ressources.soundSystem, {{"Health", 1}}),
        new PickableComponent(),
        new PowerUpPickedComponent()
    })
{
}