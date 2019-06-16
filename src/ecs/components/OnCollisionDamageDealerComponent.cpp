/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** OnCollisionDamageDealerComponent.cpp
*/

#include <iostream>
#include "OnCollisionDamageDealerComponent.hpp"
#include "../Exceptions.hpp"

namespace ECS
{
    OnCollisionDamageDealerComponent::OnCollisionDamageDealerComponent(int damage) :
        Component("OnCollisionDamageDealer"),
        damage(damage),
        ownerId(-1)
    {
    }

    std::ostream& OnCollisionDamageDealerComponent::serialize(std::ostream &stream) const
    {
    	return stream << damage << " " << ownerId << " EndOfComponent";
    }

    OnCollisionDamageDealerComponent::OnCollisionDamageDealerComponent(unsigned, ECS::Ressources &, std::istream &stream) :
        OnCollisionDamageDealerComponent(0)
    {
        std::string terminator;

	    stream >> damage >> ownerId >> terminator;
	    if (terminator != "EndOfComponent")
		    throw InvalidSerializedStringException("The component terminator was not found");
    }
}