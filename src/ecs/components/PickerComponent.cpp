/*
** EPITECH PROJECT, 2018
** ECS
** File description:
** PickerComponent.cpp
*/

#include <iostream>
#include "PickerComponent.hpp"
#include "../Exceptions.hpp"

namespace ECS
{
    PickerComponent::PickerComponent() :
        Component("Picker")
    {

    }

    std::ostream& PickerComponent::serialize(std::ostream &stream) const
    {
    	return stream << "EndOfComponent";
    }

    PickerComponent::PickerComponent(unsigned, ECS::Ressources &, std::istream &stream) :
        PickerComponent()
    {
        std::string terminator;

        stream >> terminator;
        if (terminator != "EndOfComponent")
            throw InvalidSerializedStringException("The component terminator was not found");
    }
}