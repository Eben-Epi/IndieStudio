/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** KickableComponent.cpp
*/

#include <iostream>
#include "KickableComponent.hpp"
#include "../Exceptions.hpp"

namespace ECS
{
    KickableComponent::KickableComponent()
    : Component("Kickable")
    {
    }

    std::ostream& KickableComponent::serialize(std::ostream &stream) const
    {
    	return stream << "EndOfComponent";
    }

    KickableComponent::KickableComponent(unsigned id, ECS::Ressources &ressources, std::istream &stream) :
	    KickableComponent()
    {
	    std::string terminator;

	    stream >> terminator;
	    if (terminator != "EndOfComponent")
		    throw InvalidSerializedStringException("The component terminator was not found");
    }
}