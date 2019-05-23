/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** MovableComponent.cpp
*/

#include "MovableComponent.hpp"

namespace ECS
{
    MovableComponent::MovableComponent(float maxSpeed) :
    	Component("Movable"),
      	speed(0),
    	maxSpeed(maxSpeed)
    {
    }
}