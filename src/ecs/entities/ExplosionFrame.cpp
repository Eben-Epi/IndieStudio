/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** ExplosionFrame.cpp
*/

#include "ExplosionFrame.hpp"
#include "../components/PositionComponent.hpp"
#include "../../config.hpp"
#include "../components/DisplayableComponent.hpp"
#include "../components/EphemeralComponent.hpp"
#include "../components/HealthComponent.hpp"
#include "../components/OnCollisionDamageDealerComponent.hpp"
#include "../components/CollisionComponent.hpp"
#include "../components/ColliderComponent.hpp"
#include "../components/MortalComponent.hpp"

ECS::ExplosionFrame::ExplosionFrame(unsigned id, Ressources &ressources) :
    Entity(id, "ExplosionFrame", {
        new HealthComponent(1, 30),
        new PositionComponent({0, 0}, {TILESIZE - 2, TILESIZE - 2}),
        new DisplayableComponent("ExplosionFrame", ressources),
        new EphemeralComponent(FRAME_RATE / 3),
        new MortalComponent(),
        new ColliderComponent(0),
        new CollisionComponent(0),
        new OnCollisionDamageDealerComponent(1)
    })
{
}