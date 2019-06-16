/*
** EPITECH PROJECT, 2018
** ECS
** File description:
** EphemeralComponent.cpp
*/

#include <iostream>
#include "EphemeralComponent.hpp"
#include "../Exceptions.hpp"

namespace ECS
{
	EphemeralComponent::EphemeralComponent(unsigned int timeLeft) :
		Component("Ephemeral"),
		timeLeft(timeLeft)
	{
	}

	std::ostream& EphemeralComponent::serialize(std::ostream &stream) const
	{
		return stream << timeLeft << " EndOfComponent";
	}

	EphemeralComponent::EphemeralComponent(unsigned, ECS::Ressources &, std::istream &stream) :
		EphemeralComponent(0)
	{
		std::string terminator;

		stream >> timeLeft >> terminator;
		if (terminator != "EndOfComponent")
			throw InvalidSerializedStringException("The component terminator was not found");
	}
}