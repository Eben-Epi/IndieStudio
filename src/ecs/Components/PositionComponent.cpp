/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** PositionComponent.cpp
*/

#include "PositionComponent.hpp"

namespace ECS
{
	PositionComponent::PositionComponent(Point pos) :
		Component("Position"),
		pos(pos)
	{
	}
}