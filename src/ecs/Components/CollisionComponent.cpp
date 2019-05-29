/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** SolidComponent.cpp
*/

#include "CollisionComponent.hpp"

namespace ECS
{
    CollisionComponent::CollisionComponent(unsigned int hardness, unsigned int pass):
    	Component("Collision"),
    	hardness(hardness),
        passThrough(pass)
    {
    }
}