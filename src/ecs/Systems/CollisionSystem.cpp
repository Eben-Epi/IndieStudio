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

ECS::CollisionSystem::CollisionSystem(ECS::ECSCore &core):
    System("Collision", core)
{
	this->_dependencies = {"Displayable"};
}

void ECS::CollisionSystem::updateEntity(ECS::Entity &entity)
{
	auto &col = reinterpret_cast<CollisionComponent &>(entity.getComponentByName("Collision"));
	auto &disp = reinterpret_cast<DisplayableComponent &>(entity.getComponentByName("Displayable"));

	col.entitiesCollided = {};
	for (auto &ent : this->_core.getEntitiesByComponent("Movable")) {
		if (ent->getId() == entity.getId())
			continue;

		auto &disp2 = reinterpret_cast<DisplayableComponent &>(ent->getComponentByName("Displayable"));

		if (disp.screen.areColliding(disp.entityId, disp2.entityId))
			col.entitiesCollided.push_back(&*ent);
	}
}