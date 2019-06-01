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

ECS::Bomb::Bomb(unsigned id, const Ressources &ressources) :
    Entity(id, "Brick", {
        new HealthComponent(1),
        new CollisionComponent(1, 0),
        new PositionComponent({0, 0}, {TILESIZE, TILESIZE}),
        new DisplayableComponent("Bomb", ressources),
        new EphemeralComponent(300),
        new KickableComponent(),
        new ExplodeComponent(1, 1)
    })
{
}