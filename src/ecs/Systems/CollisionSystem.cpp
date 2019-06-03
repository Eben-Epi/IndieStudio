/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** CollisionSystem.cpp
*/

#include <iostream>
#include "CollisionSystem.hpp"
#include "../ECSCore.hpp"
#include "../Components/CollisionComponent.hpp"
#include "../Components/DisplayableComponent.hpp"
#include "../Components/PositionComponent.hpp"

ECS::CollisionSystem::CollisionSystem(ECS::ECSCore &core):
    System("Collision", core)
{
	this->_dependencies = {"Displayable"};
}

void ECS::CollisionSystem::updateEntity(ECS::Entity &entity)
{
	auto &col = reinterpret_cast<CollisionComponent &>(entity.getComponentByName("Collision"));
	auto &disp = reinterpret_cast<DisplayableComponent &>(entity.getComponentByName("Displayable"));
	auto &pc = reinterpret_cast<PositionComponent &>(entity.getComponentByName("Position"));

	col.entitiesCollided = {};
	disp.screen.setPosition(disp.entityId, pc.pos.x, pc.pos.y);
	for (auto &ent : this->_core.getEntitiesByComponent("Collider")) {
		if (ent->getId() == entity.getId())
			continue;

		auto &ipc = reinterpret_cast<PositionComponent &>(ent->getComponentByName("Position"));
		auto &disp2 = reinterpret_cast<DisplayableComponent &>(ent->getComponentByName("Displayable"));
		auto &pos = reinterpret_cast<PositionComponent &>(ent->getComponentByName("Position"));

		disp2.screen.setPosition(disp2.entityId, pos.pos.x, pos.pos.y);
		if (disp.screen.areColliding(disp.entityId, disp2.entityId))
			col.entitiesCollided.push_back(&*ent);
	}
}