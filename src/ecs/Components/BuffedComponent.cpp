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

    BuffedComponent::BuffedComponent(const ECS::Ressources &, std::istream &stream) :
	    Component("Blocked"),
	    health(0),
	    speed(0),
	    nbBomb(0),
	    kick(0),
	    hardness(0)
    {
	    std::string terminator;

	    stream >> this->health;
	    stream >> this->speed;
	    stream >> this->nbBomb;
	    stream >> this->kick;
	    stream >> this->hardness;
	    stream >> terminator;
	    if (terminator != "EndOfComponent")
		    throw InvalidSerializedStringException("The component terminator was not found");
    }

    std::ostream& BuffedComponent::serialize(std::ostream &stream) const
    {
    	return stream << health << ' ' << speed << ' ' << nbBomb << ' ' << kick << ' ' << hardness << " EndOfComponent";
    }
}