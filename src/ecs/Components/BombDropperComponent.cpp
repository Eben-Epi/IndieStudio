/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** BombDropperComponent.cpp
*/

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
}