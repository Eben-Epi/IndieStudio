/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** DroppedBonusSpeed.cpp
*/

#include "DroppedBonusSpeed.hpp"
#include "../components/HealthComponent.hpp"
#include "../components/DisplayableComponent.hpp"
#include "../components/ColliderComponent.hpp"
#include "../components/PositionComponent.hpp"
#include "../../config.hpp"
#include "../components/PowerUpComponent.hpp"
#include "../components/PickableComponent.hpp"
#include "../components/PowerUpPickedComponent.hpp"
#include "../components/MortalComponent.hpp"

ECS::DroppedBonusSpeed::DroppedBonusSpeed(unsigned id, Ressources &ressources) :
    Entity(id, "DroppedBonusSpeed", {
        new HealthComponent(1),
        new DisplayableComponent("DroppedBonusSpeed", ressources),
        new ColliderComponent(0),
	new MortalComponent(),
        new PositionComponent({0, 0}, {TILESIZE, TILESIZE}),
        new PowerUpComponent(ressources.soundSystem, {{"Speed", 0.2}}),
        new PickableComponent(),
        new PowerUpPickedComponent()
    })
{
}