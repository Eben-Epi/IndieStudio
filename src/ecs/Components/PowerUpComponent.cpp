/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** PowerUpComponent.cpp
*/

#include <iostream>
#include "PowerUpComponent.hpp"

namespace ECS
{
    PowerUpComponent::PowerUpComponent(unsigned int health, float speed, unsigned int nbBomb, bool kick, unsigned int hardness) :
    	Component("PowerUp"),
    	health(health),
    	speed(speed),
    	nbBomb(nbBomb),
    	kick(kick),
    	hardness(hardness)
    {
    }

    std::ostream& PowerUpComponent::serialize(std::ostream &stream) const
    {
    	return stream << health << ' ' << speed << ' ' << nbBomb << ' ' << kick << ' ' << hardness;
    }
}