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
#include "../Exceptions.hpp"

ECS::BombDropperSystem::BombDropperSystem(ECS::ECSCore &core):
		System("BombDropper", core)
{}

void ECS::BombDropperSystem::updateEntity(ECS::Entity &entity)
{
	ECS::BombDropperComponent &bomb = reinterpret_cast<ECS::BombDropperComponent &>(entity.getComponentByName("BombDropper"));

	for (int i = 0; i < (int)bomb.bombs.size(); i++) {
		try {
			this->_core.getEntityById(bomb.bombs[i]);
		} catch (NoSuchEntityException &) {
			bomb.bombs.erase(bomb.bombs.begin() + i);
			i--;
		}
	}
	if (!bomb.dropBomb)
		return;
	if (bomb.bombs.size() >= bomb.max)
		return;

	auto &newBomb = this->_core.makeEntity("Bomb");
	auto &bomb_pos = reinterpret_cast<ECS::PositionComponent &>(newBomb.getComponentByName("Position"));
	auto &player_pos = reinterpret_cast<ECS::PositionComponent &>(entity.getComponentByName("Position"));

	bomb.soundSystem.playSound("drop_bomb");
	bomb_pos.pos.x = lround(player_pos.pos.x / TILESIZE) * TILESIZE;
	bomb_pos.pos.y = lround(player_pos.pos.y / TILESIZE) * TILESIZE;
	bomb.bombs.push_back(newBomb.getId());
	bomb.dropBomb = false;
}