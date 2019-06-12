/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** KickableComponent.cpp
*/

#include "KickableSystem.hpp"
#include "../components/ColliderComponent.hpp"
#include "../components/PositionComponent.hpp"
#include "../components/MovableComponent.hpp"
#include "../../config.hpp"
#include "../components/CollisionComponent.hpp"
#include "../components/KickerComponent.hpp"

ECS::KickableSystem::KickableSystem(ECS::ECSCore &core) :
	System("Kickable", core)
{
	this->_dependencies = {"Movable", "Collision"};
}

void ECS::KickableSystem::updateEntity(ECS::Entity &entity)
{
	auto &collision = reinterpret_cast<CollisionComponent &>(entity.getComponentByName("Collision"));

	for (Entity *i : collision.entitiesCollided) {
		auto &i_col = reinterpret_cast<ColliderComponent &>(i->getComponentByName("Collider"));

		if (collision.passThrough < i_col.hardness && !i->hasComponent("Kicker")) {
			auto &pos = reinterpret_cast<PositionComponent &>(entity.getComponentByName("Position"));
			auto &e_move = reinterpret_cast<MovableComponent &>(entity.getComponentByName("Movable"));

			pos.pos.x = (static_cast<int>(pos.pos.x) + TILESIZE / 2) / TILESIZE * TILESIZE + TILESIZE / 16;
			pos.pos.y = (static_cast<int>(pos.pos.y) + TILESIZE / 2) / TILESIZE * TILESIZE +  TILESIZE / 16;
			e_move.maxSpeed = 0;
			e_move.speed = 0;
		}
	}
}