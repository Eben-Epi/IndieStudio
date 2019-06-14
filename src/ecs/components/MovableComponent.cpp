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
    	return stream << static_cast<int>(dir) << ' ' << speed << ' ' << maxSpeed << " EndOfComponent";
    }

    MovableComponent::MovableComponent(unsigned, ECS::Ressources &, std::istream &stream) :
	    MovableComponent(0)
    {
        int val;
        std::string terminator;

        stream >> val >> speed >> maxSpeed >> terminator;
        dir = val;
        if (terminator != "EndOfComponent")
    	    throw InvalidSerializedStringException("The component terminator was not found");
    }
}