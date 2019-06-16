/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** BombDropperSystem.cpp
*/
#include "BombDropperSystem.hpp"
#include "../ECSCore.hpp"
#include "../components/HealthComponent.hpp"
#include "../components/PositionComponent.hpp"
#include "../components/EphemeralComponent.hpp"
#include "../components/ExplodeComponent.hpp"
#include "../Exceptions.hpp"
#include "../components/BlockedComponent.hpp"
#include "../components/OwnerComponent.hpp"

ECS::BombDropperSystem::BombDropperSystem(ECS::ECSCore &core):
		System("BombDropper", core)
{}

void ECS::BombDropperSystem::updateEntity(ECS::Entity &entity)
{
	ECS::BombDropperComponent &bombDropper = reinterpret_cast<ECS::BombDropperComponent &>(entity.getComponentByName("BombDropper"));

	for (unsigned i = 0; i < bombDropper.bombs.size(); i++) {
		try {
			this->_core.getEntityById(bombDropper.bombs[i]);
		} catch (NoSuchEntityException &) {
			bombDropper.bombs.erase(bombDropper.bombs.begin() + i);
			i--;
		}
	}
	if (!bombDropper.dropBomb)
		return;
	if (bombDropper.bombs.size() >= bombDropper.max)
		return;

	auto &player_pos = reinterpret_cast<ECS::PositionComponent &>(entity.getComponentByName("Position"));
	Point pos = {
		static_cast<double>(lround(player_pos.pos.x / TILESIZE) * TILESIZE) + TILESIZE / 16,
		static_cast<double>(lround(player_pos.pos.y / TILESIZE) * TILESIZE) + TILESIZE / 16
	};

	for (Entity *ent : this->_core.getEntitiesByComponent("Collider")) {
		auto &pos2 = reinterpret_cast<ECS::PositionComponent &>(ent->getComponentByName("Position"));

		if (pos2.pos.x == pos.x && pos2.pos.y == pos.y)
			return;
	}

	auto &newBomb = this->_core.makeEntity("Bomb");
	auto &bomb_pos = reinterpret_cast<ECS::PositionComponent &>(newBomb.getComponentByName("Position"));
	auto &bomb_explode = reinterpret_cast<ECS::ExplodeComponent &>(newBomb.getComponentByName("Explode"));
    auto &bomb_owner = reinterpret_cast<ECS::OwnerComponent &>(newBomb.getComponentByName("Owner"));

	bomb_pos.pos = pos;
	bomb_explode.range = bombDropper.range;
	bombDropper.bombs.push_back(newBomb.getId());
	bombDropper.soundSystem.playSound("bip");
	bombDropper.dropBomb = false;
	bomb_owner.ownerId = entity.getId();

    auto players = this->_core.getEntitiesByName("Player");
    for (auto &player : players) {
        auto &bc = reinterpret_cast<BlockedComponent &>(player->getComponentByName("Blocked"));
        bc.whitelistId.push_back(&newBomb);
    }
}