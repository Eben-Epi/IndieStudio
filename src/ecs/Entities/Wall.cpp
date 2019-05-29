/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Wall.cpp
*/

#include "Wall.hpp"
#include "../Components/CollisionComponent.hpp"
#include "../Components/PositionComponent.hpp"
#include "../Components/DisplayableComponent.hpp"
#include "../../config.hpp"

ECS::Wall::Wall(unsigned id, const Ressources &ressources) :
    Entity(id, "Wall", {
        new CollisionComponent(1),
        new PositionComponent({0, 0}, {TILESIZE, TILESIZE}),
        new DisplayableComponent("Wall", ressources)
    })
{
}