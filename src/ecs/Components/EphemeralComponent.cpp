/*
** EPITECH PROJECT, 2018
** ECS
** File description:
** EphemeralComponent.cpp
*/

#include <iostream>
#include "EphemeralComponent.hpp"

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
}