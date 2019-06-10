/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Wall.cpp
*/

#include "Wall.hpp"
#include "../Components/PositionComponent.hpp"
#include "../Components/DisplayableComponent.hpp"
#include "../Components/BlockedComponent.hpp"
#include "../Components/ColliderComponent.hpp"
#include "../../config.hpp"

ECS::Wall::Wall(unsigned id, Ressources &ressources) :
    Entity(id, "Wall", {
        new DisplayableComponent("Wall", ressources),
        new ColliderComponent(2),
        new PositionComponent({0, 0}, {TILESIZE, TILESIZE})
    })
{
}