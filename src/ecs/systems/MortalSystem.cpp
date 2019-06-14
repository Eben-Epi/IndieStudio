/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** MortalSystem.cpp
*/

#include "MortalSystem.hpp"
#include "../components/HealthComponent.hpp"

namespace ECS
{
	MortalSystem::MortalSystem(ECS::ECSCore &core) :
		System("Mortal", core)
	{
		this->_dependencies = {"Health"};
	}

	void MortalSystem::updateEntity(ECS::Entity &entity)
	{
		auto &hc = reinterpret_cast<HealthComponent &>(entity.getComponentByName("Health"));

		if (hc.health == 0)
			entity.destroy();
	}
}