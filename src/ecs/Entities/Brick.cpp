/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Brick.cpp
*/

#include "Brick.hpp"
#include "../Components/HealthComponent.hpp"
#include "../Components/ColliderComponent.hpp"
#include "../Components/PositionComponent.hpp"
#include "../Components/DisplayableComponent.hpp"
#include "../Components/BlockedComponent.hpp"
#include "../../config.hpp"
#include "../Components/MortalComponent.hpp"

ECS::Brick::Brick(unsigned id, const Ressources &ressources) :
	Entity(id, "Brick", {
		new HealthComponent(1),
		new DisplayableComponent("Brick", ressources),
		new ColliderComponent(1),
		new MortalComponent(),
		new PositionComponent({0, 0}, {TILESIZE, TILESIZE})
	})
{
}