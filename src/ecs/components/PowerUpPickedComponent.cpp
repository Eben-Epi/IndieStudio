/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** PowerUpPickedComponent.cpp
*/

#include <iostream>
#include "PowerUpPickedComponent.hpp"
#include "../Exceptions.hpp"

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

    PowerUpPickedComponent::PowerUpPickedComponent(const unsigned id, ECS::Ressources &ressources, std::istream &stream) :
        Component("PowerUpPicked")
    {
        std::string terminator;

        stream >> terminator;
        if (terminator != "EndOfComponent")
            throw InvalidSerializedStringException("The component terminator was not found");
    }
}