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
        damage(damage)
    {
    }

    std::ostream& OnCollisionDamageDealerComponent::serialize(std::ostream &stream) const
    {
    	return stream << damage << " EndOfComponent";
    }

    OnCollisionDamageDealerComponent::OnCollisionDamageDealerComponent(ECS::Ressources &, std::istream &stream) :
	    OnCollisionDamageDealerComponent(0)
    {
	    std::string terminator;

	    stream >> damage >> terminator;
	    if (terminator != "EndOfComponent")
		    throw InvalidSerializedStringException("The component terminator was not found");
    }
}