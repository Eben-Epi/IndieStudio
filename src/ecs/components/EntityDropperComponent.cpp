/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** EntityDropperComponent.cpp
*/

#include "EntityDropperComponent.hpp"
#include "../Exceptions.hpp"

namespace ECS
{
    EntityDropperComponent::EntityDropperComponent() :
    	Component("EntityDropper")
    {
    }

    EntityDropperComponent::EntityDropperComponent(const unsigned id, Ressources &ressources, std::istream &stream) :
        Component("EntityDropper")
    {
	    std::string terminator;

	    stream >> this->item >> terminator;
	    if (terminator != "EndOfComponent")
		    throw InvalidSerializedStringException("The component terminator was not found");
    }

    std::ostream& EntityDropperComponent::serialize(std::ostream &stream) const
    {
        return stream << (this->item.empty() ? "null" : this->item) << " EndOfComponent";
    }
}
