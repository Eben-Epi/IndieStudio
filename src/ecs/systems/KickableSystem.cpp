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
		// printf("%d %d %d\n", collision.passThrough, i_col.hardness, !i->hasComponent("Kicker"));
		if (collision.passThrough < i_col.hardness && !i->hasComponent("Kicker")) {
			printf("%s (%d) Collided with %s (%d)\n", entity.getName().c_str(), entity.getId(), i->getName().c_str(), i->getId());
			auto &pos = reinterpret_cast<PositionComponent &>(entity.getComponentByName("Position"));
			printf("position at %f %f (%d:%d)\n", pos.pos.x, pos.pos.y, pos.size.x, pos.size.y);
			auto &e_move = reinterpret_cast<MovableComponent &>(entity.getComponentByName("Movable"));
			pos.pos.x = (static_cast<int>(pos.pos.x) + TILESIZE / 2) / TILESIZE * TILESIZE + TILESIZE / 16;
			pos.pos.y = (static_cast<int>(pos.pos.y) + TILESIZE / 2) / TILESIZE * TILESIZE +  TILESIZE / 16;
			printf("final position at %f %f (%d:%d)\n", pos.pos.x, pos.pos.y, pos.size.x, pos.size.y);
			e_move.maxSpeed = 0;
			e_move.speed = 0;
		}
	}
}