/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** MovableComponent.cpp
*/

#include <iostream>
#include "MovableComponent.hpp"
#include "../Exceptions.hpp"

namespace ECS
{
    MovableComponent::MovableComponent(float maxSpeed):
        Component("Movable"),
        dir(UP),
        speed(0),
        maxSpeed(maxSpeed)
    {
    }

    std::ostream& MovableComponent::serialize(std::ostream &stream) const
    {
    	return stream << dir << ' ' << speed << ' ' << maxSpeed << " EndOfComponent";
    }

    MovableComponent::MovableComponent(const ECS::Ressources &, std::istream &stream) :
	    MovableComponent(0)
    {
	    std::string terminator;

	    stream >> dir >> speed >> maxSpeed >> terminator;
	    if (terminator != "EndOfComponent")
		    throw InvalidSerializedStringException("The component terminator was not found");
    }
}