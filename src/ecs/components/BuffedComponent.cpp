/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** BuffedComponent.cpp
*/

#include <iostream>
#include "BuffedComponent.hpp"
#include "../Exceptions.hpp"

namespace ECS
{
    BuffedComponent::BuffedComponent(unsigned int health, float speed, unsigned int nbBomb, bool kick, unsigned int hardness) :
    	Component("Buffed"),
    	health(health),
    	speed(speed),
    	nbBomb(nbBomb),
    	kick(kick),
    	hardness(hardness)
    {
    }

    BuffedComponent::BuffedComponent(unsigned, ECS::Ressources &, std::istream &stream) :
        BuffedComponent(0, 0.f, 0, false, 0)
    {
	    std::string terminator;

	    stream >> health >> speed >> nbBomb >> kick >> hardness >> terminator;
	    if (terminator != "EndOfComponent")
		    throw InvalidSerializedStringException("The component terminator was not found");
    }

    std::ostream& BuffedComponent::serialize(std::ostream &stream) const
    {
    	return stream << health << ' ' << speed << ' ' << nbBomb << ' ' << kick << ' ' << hardness << " EndOfComponent";
    }
}