/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** CollisionSystem.cpp
*/

#include <iostream>
#include "CollisionSystem.hpp"
#include "../ECSCore.hpp"
#include "../components/CollisionComponent.hpp"
#include "../components/DisplayableComponent.hpp"
#include "../components/PositionComponent.hpp"

ECS::CollisionSystem::CollisionSystem(ECS::ECSCore &core):
	System("Collision", core)
{
	this->_dependencies = {"Position"};
}

void ECS::CollisionSystem::updateEntity(ECS::Entity &entity)
{
	auto &col = reinterpret_cast<CollisionComponent &>(entity.getComponentByName("Collision"));
	auto &e1 = reinterpret_cast<PositionComponent &>(entity.getComponentByName("Position"));

	col.entitiesCollided = {};
	for (auto &ent : this->_core.getEntitiesByComponent("Collider")) {
		if (ent->getId() == entity.getId())
			continue;

		auto &e2 = reinterpret_cast<PositionComponent &>(ent->getComponentByName("Position"));

		if (!(
			e1.pos.x + e1.size.x < e2.pos.x ||
			e2.pos.x + e2.size.x < e1.pos.x ||
			e1.pos.y + e1.size.y < e2.pos.y ||
			e2.pos.y + e2.size.y < e1.pos.y
		))
			col.entitiesCollided.push_back(&*ent);
	}
}