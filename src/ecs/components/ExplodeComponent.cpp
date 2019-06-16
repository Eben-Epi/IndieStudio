/*
** EPITECH PROJECT, 2018
** ECS
** File description:
** ExplodeComponent.cpp
*/

#include <iostream>
#include "ExplodeComponent.hpp"
#include "../Exceptions.hpp"

namespace ECS
{
    ExplodeComponent::ExplodeComponent(Sound::SoundSystem &soundSystem, unsigned int range, unsigned int strength) :
        Component("Explode"),
        soundSystem(soundSystem),
        range(range),
        strength(strength)
    {
    }

    std::ostream& ExplodeComponent::serialize(std::ostream &stream) const
    {
    	return stream << range << ' ' << strength << " EndOfComponent";
    }

    ExplodeComponent::ExplodeComponent(unsigned, ECS::Ressources &res, std::istream &stream) :
	    ExplodeComponent(res.soundSystem, 0, 0)
    {
	    std::string terminator;

	    stream >> range >> strength >> terminator;
	    if (terminator != "EndOfComponent")
		    throw InvalidSerializedStringException("The component terminator was not found");
    }
}