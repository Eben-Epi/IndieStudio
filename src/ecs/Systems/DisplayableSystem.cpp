/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** DisplayableSystem.cpp
*/

#include "DisplayableSystem.hpp"
#include "../Components/DisplayableComponent.hpp"
#include "../Components/PositionComponent.hpp"


ECS::DisplayableSystem::DisplayableSystem(ECS::ECSCore &core):
    System("Displayable", core)
{}

void ECS::DisplayableSystem::updateEntity(ECS::Entity &entity)
{
	DisplayableComponent	&disp = reinterpret_cast<DisplayableComponent &>(entity.getComponentByName("Displayable"));
	PositionComponent	&pos = reinterpret_cast<PositionComponent &>(entity.getComponentByName("Position"));

	disp.screen.setPosition(disp.entityId, pos.pos.x, pos.pos.y);
	disp.screen.setAnimation(disp.entityId, disp.animation);
}