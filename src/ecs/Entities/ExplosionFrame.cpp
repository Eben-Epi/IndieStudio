/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** ExplosionFrame.cpp
*/

#include "ExplosionFrame.hpp"
#include "../Components/PositionComponent.hpp"
#include "../../config.hpp"
#include "../Components/DisplayableComponent.hpp"
#include "../Components/EphemeralComponent.hpp"
#include "../Components/HealthComponent.hpp"
#include "../Components/OnCollisionDamageDealerComponent.hpp"
#include "../Components/CollisionComponent.hpp"
#include "../Components/ColliderComponent.hpp"
#include "../Components/MortalComponent.hpp"

ECS::ExplosionFrame::ExplosionFrame(unsigned id, const Ressources &ressources) :
    Entity(id, "ExplosionFrame", {
        new HealthComponent(1),
        new PositionComponent({0, 0}, {TILESIZE, TILESIZE}),
        new DisplayableComponent("ExplosionFrame", ressources),
        new EphemeralComponent(60),
        new MortalComponent(),
        new ColliderComponent(0),
        new CollisionComponent(0),
        new OnCollisionDamageDealerComponent(1)
    })
{
}