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
	Component("Blocked")
{}

ECS::BlockedComponent::BlockedComponent(const ECS::Ressources &, std::istream &stream) :
	Component("Blocked")
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