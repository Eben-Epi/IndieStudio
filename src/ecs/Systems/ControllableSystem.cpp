/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** ControllableSystem.cpp
*/

#include <iostream>
#include "ControllableSystem.hpp"
#include "../Components/PositionComponent.hpp"
#include "../Components/MovableComponent.hpp"
#include "../Components/ControllableComponent.hpp"
#include "../Components/CurseComponent.hpp"

namespace ECS
{
	ControllableSystem::ControllableSystem(ECS::ECSCore &core) :
		System("Controllable", core)
	{
		this->_dependencies = {"Movable", "Position"};
	}

	void ControllableSystem::updateEntity(ECS::Entity &entity)
	{
		auto &mov = reinterpret_cast<MovableComponent &>(entity.getComponentByName("Movable"));
		auto &pos = reinterpret_cast<PositionComponent &>(entity.getComponentByName("Position"));
		auto &in = reinterpret_cast<ControllableComponent &>(entity.getComponentByName("Controllable"));
		auto actions = in.input.getActions();
		unsigned char newDir = 0;

		for (auto &action : actions) {
			switch (action) {
			case Input::ACTION_UP:
			case Input::ACTION_DOWN:
			case Input::ACTION_LEFT:
			case Input::ACTION_RIGHT:
				newDir = 1U << action;
				break;
			default:
				break;
			}
		}
		if (newDir) {
			if (IS_CURSED(entity, CurseComponent::REVERSECONTROL))
				mov.dir = (newDir << 2) | (newDir >> 2);
			else
				mov.dir = newDir;
			mov.speed = mov.speed > 0 ? mov.speed : mov.maxSpeed / 2;
		} else
			mov.speed = 0;
	}
}