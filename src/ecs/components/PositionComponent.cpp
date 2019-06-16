/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** PositionComponent.cpp
*/

#include <iostream>
#include "PositionComponent.hpp"
#include "../Exceptions.hpp"

namespace ECS
{
	PositionComponent::PositionComponent(ECS::Point pos, ECS::Vector2<unsigned int> size) :
		Component("Position"),
		pos(pos),
		size(size)
	{
	}

	std::ostream& PositionComponent::serialize(std::ostream &stream) const
	{
		return stream << pos.x << ' ' << pos.y << ' ' << size.x << ' ' << size.y << " EndOfComponent";
	}

	PositionComponent::PositionComponent(unsigned id, ECS::Ressources &ressources, std::istream &stream) :
		PositionComponent({0, 0}, {0, 0})
	{
		std::string terminator;

		stream >> pos.x >> pos.y >> size.x >> size.y >> terminator;
		if (terminator != "EndOfComponent")
			throw InvalidSerializedStringException("The component terminator was not found");
	}
}