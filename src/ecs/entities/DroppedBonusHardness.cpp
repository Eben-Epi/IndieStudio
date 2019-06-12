/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** DroppedBonusHardness.cpp
*/

#include "DroppedBonusHardness.hpp"
#include "../components/HealthComponent.hpp"
#include "../components/DisplayableComponent.hpp"
#include "../components/ColliderComponent.hpp"
#include "../components/PositionComponent.hpp"
#include "../../config.hpp"
#include "../components/PowerUpComponent.hpp"
#include "../components/PickableComponent.hpp"
#include "../components/PowerUpPickedComponent.hpp"
#include "../components/MortalComponent.hpp"

ECS::DroppedBonusHardness::DroppedBonusHardness(unsigned id, Ressources &ressources) :
    Entity(id, "DroppedBonusHardness", {
        new HealthComponent(1),
        new DisplayableComponent("DroppedBonusHardness", ressources),
        new ColliderComponent(0),
	new MortalComponent(),
        new PositionComponent({0, 0}, {TILESIZE, TILESIZE}),
        new PowerUpComponent(ressources.soundSystem, {{"Hardness", 1}}),
        new PickableComponent(),
        new PowerUpPickedComponent()
    })
{
}