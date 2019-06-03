/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** SolidComponent.cpp
*/

#include <iostream>
#include "CollisionComponent.hpp"

namespace ECS
{
    CollisionComponent::CollisionComponent(unsigned int pass):
    	Component("Collision"),
        passThrough(pass)
    {
    }

    std::ostream& CollisionComponent::serialize(std::ostream &stream) const
    {
    	return stream << passThrough;
    }
}