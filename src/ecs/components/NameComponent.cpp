/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** NameComponent.cpp
*/

#include "NameComponent.hpp"
#include "../Exceptions.hpp"

namespace ECS
{
	NameComponent::NameComponent(const std::string &name) :
		Component("Name"),
		name(name)
	{
		for (char c : name)
			if (isspace(c))
				throw InvalidNameException("Invalid name: " + name);
	}

	std::ostream& NameComponent::serialize(std::ostream &stream) const
	{
		return stream << name << " EndOfComponent";
	}

	NameComponent::NameComponent(unsigned, ECS::Ressources &, std::istream &stream) :
		NameComponent("")
	{
		std::string terminator;

		stream >> name >> terminator;
		if (terminator != "EndOfComponent")
			throw InvalidSerializedStringException("The component terminator was not found");
	}
}