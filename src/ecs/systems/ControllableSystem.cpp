/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** ControllableSystem.cpp
*/

#include <iostream>
#include "ControllableSystem.hpp"
#include "../components/PositionComponent.hpp"
#include "../components/MovableComponent.hpp"
#include "../components/ControllableComponent.hpp"
#include "../components/CurseComponent.hpp"
#include "../components/BombDropperComponent.hpp"
#include "../components/UltimeComponent.hpp"
#include "../components/DisplayableComponent.hpp"

namespace ECS
{
	ControllableSystem::ControllableSystem(ECS::ECSCore &core) :
		System("Controllable", core)
	{
		this->_dependencies = {"Movable", "Position", "BombDropper", "Ultime", "Displayable"};
	}

	void ControllableSystem::updateEntity(ECS::Entity &entity)
	{
		auto &in = reinterpret_cast<ControllableComponent &>(entity.getComponentByName("Controllable"));
		auto &mov = reinterpret_cast<MovableComponent &>(entity.getComponentByName("Movable"));
		auto &bombDropper = reinterpret_cast<BombDropperComponent &>(entity.getComponentByName("BombDropper"));
		auto &uc = reinterpret_cast<UltimeComponent &>(entity.getComponentByName("Ultime"));
		auto &disp = reinterpret_cast<DisplayableComponent &>(entity.getComponentByName("Displayable"));
		unsigned char newDir = 0;

		uc.castUlt = false;
		disp.animation = Irrlicht::IDLE;
		bombDropper.dropBomb = false;
		if (in.stunLeft > 0) {
			in.stunLeft -= 1;
			mov.speed = 0;
			return;
		}

		auto actions = in.input.getActions();
		for (auto &action : actions) {
			switch (action) {
			case Input::ACTION_UP:
			case Input::ACTION_DOWN:
			case Input::ACTION_LEFT:
			case Input::ACTION_RIGHT:
				newDir = 1U << action;
				break;
			case Input::ACTION_ACTION:
				bombDropper.dropBomb = true;
				break;
			case Input::ACTION_ULT:
				uc.castUlt = true;
			}
		}
		if (IS_CURSED(entity, CurseComponent::AUTODROP))
			bombDropper.dropBomb = true;
		if (IS_CURSED(entity, CurseComponent::NODROP))
			bombDropper.dropBomb = false;
		if (newDir) {
			if (IS_CURSED(entity, CurseComponent::REVERSECONTROL))
				mov.dir = (newDir << 2) | (newDir >> 2);
			else
				mov.dir = newDir;
			mov.speed = mov.speed > 0 ? mov.speed : mov.maxSpeed / 2;
			disp.animation = Irrlicht::RUN;
		} else
			mov.speed = 0;
	}
}