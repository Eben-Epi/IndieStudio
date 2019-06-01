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

ECS::ExplosionFrame::ExplosionFrame(unsigned id, const Ressources &ressources) :
    Entity(id, "ExplosionFrame", {
        new HealthComponent(1),
        new PositionComponent({0, 0}, {TILESIZE, TILESIZE}),
        new DisplayableComponent("ExplosionFrame", ressources),
        new EphemeralComponent(60),
        new OnCollisionDamageDealerComponent(1)
    })
{
}