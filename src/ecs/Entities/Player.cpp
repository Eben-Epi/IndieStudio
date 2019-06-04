/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Player.cpp
*/

#include "Player.hpp"
#include "../Components/HealthComponent.hpp"
#include "../Components/PositionComponent.hpp"
#include "../Components/DisplayableComponent.hpp"
#include "../Components/ControllableComponent.hpp"
#include "../Components/MovableComponent.hpp"
#include "../Components/CollisionComponent.hpp"
#include "../Components/BlockedComponent.hpp"
#include "../Components/ColliderComponent.hpp"
#include "../../config.hpp"

ECS::Player::Player(unsigned id, const Ressources &ressources) :
	Entity(id, "Player", {
		new PositionComponent({0, 0}, {TILESIZE - TILESIZE / 8, TILESIZE - TILESIZE / 8}),
		new DisplayableComponent("Player", ressources),
		new HealthComponent(1),
		new MovableComponent(5),
		new CollisionComponent(0),
		new ColliderComponent(0),
		new BlockedComponent(),
		new ControllableComponent(*ressources.inputs.at(id), id)
	})
{
}
