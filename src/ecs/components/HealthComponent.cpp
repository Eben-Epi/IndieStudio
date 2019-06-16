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
	HealthComponent::HealthComponent(unsigned int health, unsigned unvulnerability) :
		Component("Health"),
		health(health),
		invunerabilityTimeLeft(unvulnerability)
	{
	}

	std::ostream& HealthComponent::serialize(std::ostream &stream) const
	{
		return stream << health << " " << invunerabilityTimeLeft << " EndOfComponent";
	}

	bool HealthComponent::takeDamage(int damage, unsigned int invulnerability_given)
	{
		if (this->invunerabilityTimeLeft)
			return false;
		if (this->health > damage)
			this->health -= damage;
		else
			this->health = 0;
		this->invunerabilityTimeLeft = invulnerability_given;
		return true;
	}

	HealthComponent::HealthComponent(unsigned, ECS::Ressources &, std::istream &stream) :
		HealthComponent(0)
	{
		std::string terminator;

		stream >> health >> invunerabilityTimeLeft >> terminator;
		if (terminator != "EndOfComponent")
			throw InvalidSerializedStringException("The component terminator was not found");
	}
}