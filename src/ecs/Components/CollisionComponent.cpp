/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** SolidComponent.cpp
*/

#include "CollisionComponent.hpp"

namespace ECS
{
    CollisionComponent::CollisionComponent(unsigned int hardness) :
    	Component("Collision"),
    	hardness(hardness)
    {
    }
}