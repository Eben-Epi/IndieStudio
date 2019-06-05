/*
** EPITECH PROJECT, 2018
** ECS
** File description:
** ExplodeComponent.cpp
*/

#include <iostream>
#include "ExplodeComponent.hpp"
#include "../Exceptions.hpp"

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
    	return stream << range << ' ' << strength << " EndOfComponent";
    }

    ExplodeComponent::ExplodeComponent(const ECS::Ressources &, std::istream &stream) :
	    ExplodeComponent(0, 0)
    {
	    std::string terminator;

	    stream >> range >> strength >> terminator;
	    if (terminator != "EndOfComponent")
		    throw InvalidSerializedStringException("The component terminator was not found");
    }
}