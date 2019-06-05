/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** BombDropperSystem.cpp
*/
#include "BombDropperSystem.hpp"
#include "../ECSCore.hpp"
#include "../Components/HealthComponent.hpp"

ECS::BombDropperSystem::BombDropperSystem(ECS::ECSCore &core):
    System("BombDropper", core)
{}

void ECS::BombDropperSystem::updateEntity(ECS::Entity &entity)
{
    ECS::BombDropperComponent &bomb = reinterpret_cast<ECS::BombDropperComponent &>(entity.getComponentByName("BombDropper"));
    for (size_t i = 0; i != bomb.bombs.size(); i++) {
      auto &health = reinterpret_cast<ECS::HealthComponent &>(bomb.bombs[i]->getComponentByName("Health"));
      if (health.health == 0)
        bomb.bombs.erase(bomb.bombs.begin() + i);
    }
    if (bomb.max >= bomb.bombs.size())
      return;
    else
      bomb.bombs.push_back(&this->_core.makeEntity("Bomb"));
}