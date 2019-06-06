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
	BombDropperComponent::BombDropperComponent(unsigned max, float timeToExplode, unsigned range) :
		Component ("BombDropper"),
		max(max),
		timeToExplode(timeToExplode),
		range(range),
		dropBomb(false)
	{
	}

	BombDropperComponent::BombDropperComponent(const ECS::Ressources &, std::istream &stream) :
		BombDropperComponent(0, 0, 0)
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