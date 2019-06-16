/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** MortalComponent.cpp
*/

#include "MortalComponent.hpp"
#include "../Exceptions.hpp"

namespace ECS
{
	MortalComponent::MortalComponent() :
		Component("Mortal")
	{
	}

	MortalComponent::MortalComponent(const unsigned id, ECS::Ressources &ressources, std::istream &stream) :
		MortalComponent()
	{
		std::string terminator;

		stream >> terminator;
		if (terminator != "EndOfComponent")
			throw InvalidSerializedStringException("The component terminator was not found");
	}

	std::ostream& MortalComponent::serialize(std::ostream &stream) const
	{
		return stream << "EndOfComponent";
	}
}