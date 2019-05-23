/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** PowerUpComponent.cpp
*/

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
}