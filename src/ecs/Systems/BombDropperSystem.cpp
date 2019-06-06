/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** BombDropperSystem.cpp
*/
#include "BombDropperSystem.hpp"
#include "../ECSCore.hpp"
#include "../Components/HealthComponent.hpp"
#include "../Components/PositionComponent.hpp"
#include "../Components/EphemeralComponent.hpp"
#include "../Components/ExplodeComponent.hpp"

ECS::BombDropperSystem::BombDropperSystem(ECS::ECSCore &core):
		System("BombDropper", core)
{}

void ECS::BombDropperSystem::updateEntity(ECS::Entity &entity)
{
	static int clock = 0;
	ECS::BombDropperComponent &bomb = reinterpret_cast<ECS::BombDropperComponent &>(entity.getComponentByName("BombDropper"));

	for (int i = 0; i < (int)bomb.bombs.size(); i++) {
		auto &exploded = reinterpret_cast<ECS::ExplodeComponent &>(bomb.bombs[i]->getComponentByName("Explode"));
		if (exploded.exploded) {
			bomb.bombs.erase(bomb.bombs.begin() + i);
			i--;
		}
	}
	if (!bomb.dropBomb || clock > 0) {
		if (clock > 0)
			clock--;
		return;
	}
	if (bomb.bombs.size() >= bomb.max) {
		bomb.dropBomb = false;
		return;
	}
	auto &newBomb = this->_core.makeEntity("Bomb");
	auto &bomb_pos = reinterpret_cast<ECS::PositionComponent &>(newBomb.getComponentByName("Position"));
	auto &player_pos = reinterpret_cast<ECS::PositionComponent &>(entity.getComponentByName("Position"));
	bomb_pos.pos = player_pos.pos;
	// bomb_pos.pos.x = static_cast<int>(player_pos.pos.x) & (0xFFFFFFFF - TILESIZE + 1);
	// bomb_pos.pos.y = static_cast<int>(player_pos.pos.y) & (0xFFFFFFFF - TILESIZE + 1);
	bomb.bombs.push_back(&newBomb);
	bomb.dropBomb = false;
	clock = 50;
}