/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** BuffedComponent.cpp
*/

#include "BuffedComponent.hpp"

namespace ECS
{
    BuffedComponent::BuffedComponent(unsigned int health, float speed, unsigned int nbBomb, bool kick, unsigned int hardness) :
    	Component("PowerUp"),
    	health(health),
    	speed(speed),
    	nbBomb(nbBomb),
    	kick(kick),
    	hardness(hardness)
    {
    }
}