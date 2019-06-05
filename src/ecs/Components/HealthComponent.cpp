/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** HealthComponent.cpp
*/

#include <iostream>
#include "HealthComponent.hpp"
#include "../Exceptions.hpp"

namespace ECS
{
	HealthComponent::HealthComponent(unsigned int health) :
		Component("Health"),
		health(health),
		invunerabilityTimeLeft(0)
	{
	}

	std::ostream& HealthComponent::serialize(std::ostream &stream) const
	{
		return stream << health << " EndOfComponent";
	}

	bool HealthComponent::takeDamage(int damage, unsigned int invulnerability_given)
    {
        if (this->invunerabilityTimeLeft)
            return false;
        this->health -= damage;
        this->invunerabilityTimeLeft = invulnerability_given;
        return true;
    }

	HealthComponent::HealthComponent(const ECS::Ressources &, std::istream &stream) :
		HealthComponent(0)
	{
		std::string terminator;

		stream >> health  >> terminator;
		if (terminator != "EndOfComponent")
			throw InvalidSerializedStringException("The component terminator was not found");
	}
}