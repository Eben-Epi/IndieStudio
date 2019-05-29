/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** HealthComponent.cpp
*/

#include "HealthComponent.hpp"

namespace ECS
{
	HealthComponent::HealthComponent(unsigned int health) :
		Component("Health"),
		health(health)
	{
	}
}