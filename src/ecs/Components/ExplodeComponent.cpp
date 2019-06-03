/*
** EPITECH PROJECT, 2018
** ECS
** File description:
** ExplodeComponent.cpp
*/

#include <iostream>
#include "ExplodeComponent.hpp"

namespace ECS
{
    ExplodeComponent::ExplodeComponent(unsigned int range, unsigned int strength) :
        Component("Controller"),
        range(range),
        strength(strength)
    {
    }

    std::ostream& ExplodeComponent::serialize(std::ostream &stream) const
    {
    	return stream << range << ' ' << strength;
    }
}