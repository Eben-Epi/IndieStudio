/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** PowerUpPickedComponent.cpp
*/

#include <iostream>
#include "PowerUpPickedComponent.hpp"

namespace ECS
{
    PowerUpPickedComponent::PowerUpPickedComponent() :
        Component("PowerUpPicked")
    {

    }

    std::ostream& PowerUpPickedComponent::serialize(std::ostream &stream) const
    {
    	return stream << "EndOfComponent";
    }
}