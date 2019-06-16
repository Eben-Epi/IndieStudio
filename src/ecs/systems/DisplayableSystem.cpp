/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** DisplayableSystem.cpp
*/

#include "DisplayableSystem.hpp"
#include "../components/DisplayableComponent.hpp"
#include "../components/PositionComponent.hpp"
#include "../components/MovableComponent.hpp"
#include "../../irrlicht/game-scene/GameScene.hpp"

#define M_PI_2		1.57079632679489661923

ECS::DisplayableSystem::DisplayableSystem(ECS::ECSCore &core):
    System("Displayable", core)
{}

void ECS::DisplayableSystem::updateEntity(ECS::Entity &entity)
{
	DisplayableComponent	&disp = reinterpret_cast<DisplayableComponent &>(entity.getComponentByName("Displayable"));
	PositionComponent	&pos = reinterpret_cast<PositionComponent &>(entity.getComponentByName("Position"));

	disp.gameScene.setSize(disp.entityId, pos.size.x, pos.size.y);
	disp.gameScene.setPosition(disp.entityId, pos.pos.x, pos.pos.y);
	disp.gameScene.setAnimation(disp.entityId, disp.animation);
	if (entity.hasComponent("Movable")) {
		auto &mov = reinterpret_cast<MovableComponent &>(entity.getComponentByName("Movable"));
		float f = (float)(mov.dir & -mov.dir);
		float angle = ((*(uint32_t *)&f >> 23) - 0x7f) * M_PI_2;

		disp.gameScene.setRotation(disp.entityId, angle - M_PI_2);
	}
}