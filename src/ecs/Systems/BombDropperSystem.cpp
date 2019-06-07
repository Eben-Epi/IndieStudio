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

	bomb_pos.pos.x = lround(player_pos.pos.x / TILESIZE) * TILESIZE;
	bomb_pos.pos.y = lround(player_pos.pos.y / TILESIZE) * TILESIZE;
	bomb.bombs.push_back(&newBomb);
	bomb.dropBomb = false;
	clock = 50;
}