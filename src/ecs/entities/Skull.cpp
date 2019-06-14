/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Skull.cpp
*/
#include "Skull.hpp"
#include "../components/HealthComponent.hpp"
#include "../components/DisplayableComponent.hpp"
#include "../components/ColliderComponent.hpp"
#include "../components/MortalComponent.hpp"
#include "../components/PositionComponent.hpp"
#include "../components/PickableComponent.hpp"
#include "../components/CurseOnPickComponent.hpp"

ECS::Skull::Skull(unsigned id, Ressources &ressources) :
    Entity(id, "Skull", {
        new HealthComponent(1),
        new DisplayableComponent("Skull", ressources),
        new ColliderComponent(0),
        new MortalComponent(),
        new PositionComponent({0, 0}, {TILESIZE, TILESIZE}),
        new PickableComponent(),
        new CurseOnPickComponent(ressources.soundSystem)
    })
{}