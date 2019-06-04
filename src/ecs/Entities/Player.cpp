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
#include "../../config.hpp"
#include "../Components/BlockedComponent.hpp"
#include "../Components/ColliderComponent.hpp"

ECS::Player::Player(unsigned id, const Ressources &ressources) :
	Entity(id, "Player", {
		new ControllableComponent(*ressources.inputs.at(id), id),
		new MovableComponent(5),
        new PositionComponent({0, 0}, {TILESIZE - TILESIZE / 8, TILESIZE - TILESIZE / 8}),
        new HealthComponent(1),
        new CollisionComponent(0),
        new ColliderComponent(0),
        new BlockedComponent(),
        new DisplayableComponent("Player", ressources)
    })
{}
