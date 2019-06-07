/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** BombDropperComponent.cpp
*/

#include <iostream>
#include "BombDropperComponent.hpp"
#include "../Exceptions.hpp"

namespace ECS
{
	BombDropperComponent::BombDropperComponent(Sound::SoundSystem &soundSystem, unsigned max, float timeToExplode, unsigned range) :
		Component ("BombDropper"),
		soundSystem(soundSystem),
		max(max),
		timeToExplode(timeToExplode),
		range(range),
		dropBomb(false)
	{
	}

	BombDropperComponent::BombDropperComponent(ECS::Ressources &res, std::istream &stream) :
		BombDropperComponent(res.soundSystem)
	{
		std::string terminator;

		stream >> max >> timeToExplode >> range >> terminator;
		if (terminator != "EndOfComponent")
			throw InvalidSerializedStringException("The component terminator was not found");
	}

	std::ostream &BombDropperComponent::serialize(std::ostream &stream) const
	{
		return stream << max << ' ' << timeToExplode << ' ' << range << " EndOfComponent";
	}
}