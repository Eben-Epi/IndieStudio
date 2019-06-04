/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** BombDropperComponent.cpp
*/

#include <iostream>
#include "BombDropperComponent.hpp"

namespace ECS
{
	BombDropperComponent::BombDropperComponent(unsigned max, float timeToExplode, unsigned range) :
		Component ("BombDropper"),
		max(max),
		timeToExplode(timeToExplode),
		range(range)
	{
	}

	std::ostream &BombDropperComponent::serialize(std::ostream &stream) const
	{
		return stream << max << ' ' << timeToExplode << ' ' << range << " EndOfComponent";
	}
}