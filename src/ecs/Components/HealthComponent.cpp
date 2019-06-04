/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** HealthComponent.cpp
*/

#include <iostream>
#include "HealthComponent.hpp"

namespace ECS
{
	HealthComponent::HealthComponent(unsigned int health) :
		Component("Health"),
		health(health)
	{
	}

	std::ostream& HealthComponent::serialize(std::ostream &stream) const
	{
		return stream << health << " EndOfComponent";
	}
}