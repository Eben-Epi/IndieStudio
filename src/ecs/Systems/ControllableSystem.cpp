/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** ControllableSystem.cpp
*/

#include "ControllableSystem.hpp"
#include "../Components/PositionComponent.hpp"
#include "../Components/MovableComponent.hpp"
#include "../Components/ControllableComponent.hpp"

namespace ECS
{
	ControllableSystem::ControllableSystem(ECS::ECSCore &core) :
		System("Controllable", core)
	{
	}

	void ControllableSystem::updateEntity(ECS::Entity &entity)
	{
		MovableComponent      &mov = reinterpret_cast<MovableComponent &>(entity.getComponentByName("Movable"));
		PositionComponent     &pos = reinterpret_cast<PositionComponent &>(entity.getComponentByName("Position"));
		ControllableComponent &in = reinterpret_cast<ControllableComponent &>(entity.getComponentByName("Controllable"));


	}
}