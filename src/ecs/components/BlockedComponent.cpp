/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** BlockedComponent.cpp
*/

#include <iostream>
#include "BlockedComponent.hpp"
#include "../Exceptions.hpp"

ECS::BlockedComponent::BlockedComponent() :
	Component("Blocked"),
	whitelistId({})
{}

ECS::BlockedComponent::BlockedComponent(unsigned, ECS::Ressources &, std::istream &stream) :
	BlockedComponent()
{
	std::string terminator;

	stream >> terminator;
	if (terminator != "EndOfComponent")
		throw InvalidSerializedStringException("The component terminator was not found");
}

std::ostream &ECS::BlockedComponent::serialize(std::ostream &stream) const
{
	return stream << "EndOfComponent";
}
