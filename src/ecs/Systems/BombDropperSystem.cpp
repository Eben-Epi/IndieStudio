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

ECS::BombDropperSystem::BombDropperSystem(ECS::ECSCore &core):
		System("BombDropper", core)
{}

void ECS::BombDropperSystem::updateEntity(ECS::Entity &entity)
{
	ECS::BombDropperComponent &bomb = reinterpret_cast<ECS::BombDropperComponent &>(entity.getComponentByName("BombDropper"));
	if (!bomb.dropBomb)
		return;
	for (size_t i = 0; i != bomb.bombs.size(); i++) {
		auto &health = reinterpret_cast<ECS::HealthComponent &>(bomb.bombs[i]->getComponentByName("Health"));
		if (health.health == 0)
			bomb.bombs.erase(bomb.bombs.begin() + i);
	}
	if (bomb.bombs.size() >= bomb.max) {
		bomb.dropBomb = false;
		return;
	}
	std::cout << "bomb dropped\n";
	auto &newBomb = this->_core.makeEntity("Bomb");
	auto &bomb_pos = reinterpret_cast<ECS::PositionComponent &>(newBomb.getComponentByName("Position"));
	auto &player_pos = reinterpret_cast<ECS::PositionComponent &>(entity.getComponentByName("Position"));
	bomb_pos.pos = player_pos.pos;
	// bomb_pos.pos.x = static_cast<int>(player_pos.pos.x) & (0xFFFFFFFF - TILESIZE + 1);
	// bomb_pos.pos.y = static_cast<int>(player_pos.pos.y) & (0xFFFFFFFF - TILESIZE + 1);
	bomb.bombs.push_back(&newBomb);
	bomb.dropBomb = false;
}