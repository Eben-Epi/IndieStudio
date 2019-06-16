/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Bomb.cpp
*/

#include "Bomb.hpp"
#include "../components/HealthComponent.hpp"
#include "../components/CollisionComponent.hpp"
#include "../components/PositionComponent.hpp"
#include "../../config.hpp"
#include "../components/DisplayableComponent.hpp"
#include "../components/EphemeralComponent.hpp"
#include "../components/KickableComponent.hpp"
#include "../components/ExplodeComponent.hpp"
#include "../components/ColliderComponent.hpp"
#include "../components/MovableComponent.hpp"
#include "../components/BlockedComponent.hpp"
#include "../components/OwnerComponent.hpp"

ECS::Bomb::Bomb(unsigned id, Ressources &ressources) :
    Entity(id, "Bomb", {
        new HealthComponent(1),
        new ColliderComponent(2),
        new CollisionComponent(0),
        new KickableComponent(),
        new MovableComponent(0),
        new PositionComponent({0, 0}, {TILESIZE - TILESIZE / 8, TILESIZE - TILESIZE / 8}),
        new EphemeralComponent(3 * FRAME_RATE),
        new ExplodeComponent(ressources.soundSystem, 1, 1),
        new OwnerComponent(),
        new DisplayableComponent("Bomb", ressources)
    })
{
}