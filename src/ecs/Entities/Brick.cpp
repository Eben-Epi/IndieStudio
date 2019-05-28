/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Brick.cpp
*/

#include "Brick.hpp"
#include "../Components/HealthComponent.hpp"
#include "../Components/CollisionComponent.hpp"
#include "../Components/PositionComponent.hpp"
#include "../Components/DisplayableComponent.hpp"

ECS::Brick::Brick(unsigned id, const Ressources &ressources) :
	Entity(id, "Brick", {
		new HealthComponent(1),
		new CollisionComponent(1),
		new PositionComponent({0, 0}, {64, 64}),
		new DisplayableComponent("Brick", ressources)
	})
{
}