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
		range(range)
	{
	}

	BombDropperComponent::BombDropperComponent(const ECS::Ressources &, std::istream &stream) :
		Component("BombDropper"),
		max(0),
		timeToExplode(0),
		range(0)
	{
		std::string terminator;

		stream >> this->max;
		stream >> this->timeToExplode;
		stream >> this->range;
		stream >> terminator;
		if (terminator != "EndOfComponent")
			throw InvalidSerializedStringException("The component terminator was not found");
	}

	std::ostream &BombDropperComponent::serialize(std::ostream &stream) const
	{
		return stream << max << ' ' << timeToExplode << ' ' << range << " EndOfComponent";
	}
}