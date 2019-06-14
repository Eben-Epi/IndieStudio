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
		Component("BombDropper"),
		soundSystem(soundSystem),
		max(max),
		timeToExplode(timeToExplode),
		range(range),
		dropBomb(false)
	{
	}

	BombDropperComponent::BombDropperComponent(unsigned, ECS::Ressources &res, std::istream &stream) :
		BombDropperComponent(res.soundSystem)
	{
		unsigned size;
		std::string value;

		stream >> max >> timeToExplode >> range >> size;
		while (size--) {
			stream >> value;
			this->bombs.push_back(std::stoi(value));
		}
		stream >> value;
		if (value != "EndOfComponent")
			throw InvalidSerializedStringException("The component terminator was not found");
	}

	std::ostream &BombDropperComponent::serialize(std::ostream &stream) const
	{
		stream << max << ' ' << timeToExplode << ' ' << range << ' ' << this->bombs.size() << ' ';
		for (auto &bomb : this->bombs)
			stream << bomb << " ";
		return stream << "EndOfComponent";
	}
}