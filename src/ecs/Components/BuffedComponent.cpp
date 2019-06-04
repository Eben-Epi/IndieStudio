/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** BuffedComponent.cpp
*/

#include <iostream>
#include "BuffedComponent.hpp"

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

    std::ostream& BuffedComponent::serialize(std::ostream &stream) const
    {
    	return stream << health << ' ' << speed << ' ' << nbBomb << ' ' << kick << ' ' << hardness << " EndOfComponent";
    }
}