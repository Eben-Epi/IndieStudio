/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** PositionComponent.cpp
*/

#include <iostream>
#include "PositionComponent.hpp"

namespace ECS
{
	PositionComponent::PositionComponent(ECS::PointF pos, ECS::Vector2<unsigned int> size) :
		Component("Position"),
		pos(pos),
		size(size)
	{
	}

	std::ostream& PositionComponent::serialize(std::ostream &stream) const
	{
		return stream << pos.x << ' ' << pos.y << ' ' << size.x << ' ' << size.y << " EndOfComponent";
	}
}