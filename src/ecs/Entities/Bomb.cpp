/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Bomb.cpp
*/

#include "Bomb.hpp"
#include "../Components/HealthComponent.hpp"
#include "../Components/CollisionComponent.hpp"
#include "../Components/PositionComponent.hpp"
#include "../../config.hpp"
#include "../Components/DisplayableComponent.hpp"
#include "../Components/EphemeralComponent.hpp"
#include "../Components/KickableComponent.hpp"
#include "../Components/ExplodeComponent.hpp"
#include "../Components/ColliderComponent.hpp"
#include "../Components/MovableComponent.hpp"

ECS::Bomb::Bomb(unsigned id, const Ressources &ressources) :
    Entity(id, "Bomb", {
        new HealthComponent(1),
        new ColliderComponent(2),
        new CollisionComponent(0),
        new MovableComponent(0),
        new PositionComponent({0, 0}, {TILESIZE - TILESIZE / 8, TILESIZE - TILESIZE / 8}),
        new EphemeralComponent(300),
        new MovableComponent(2),
        new KickableComponent(),
        new ExplodeComponent(1, 1),
	new DisplayableComponent("Bomb", ressources)
    })
{
}