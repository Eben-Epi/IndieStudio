/*
** EPITECH PROJECT, 2018
** ECS
** File description:
** PickableComponent.cpp
*/

#include <iostream>
#include "PickableComponent.hpp"
#include "../Exceptions.hpp"

namespace ECS
{
    PickableComponent::PickableComponent() :
        Component("Pickable")
    {

    }

    std::ostream& PickableComponent::serialize(std::ostream &stream) const
    {
    	return stream << " EndOfComponent";
    }

    PickableComponent::PickableComponent(unsigned, ECS::Ressources &, std::istream &stream) :
        PickableComponent()
    {
        std::string terminator;

        stream >> terminator;
        if (terminator != "EndOfComponent")
            throw InvalidSerializedStringException("The component terminator was not found");
    }
}