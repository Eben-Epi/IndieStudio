/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** BombDropperSystem.cpp
*/
#include "BombDropperSystem.hpp"
#include "../ECSCore.hpp"

ECS::BombDropperSystem::BombDropperSystem(ECS::ECSCore &core):
    System("BombDropper", core)
{}

void ECS::BombDropperSystem::updateEntity(ECS::Entity &entity)
{
  ECS::BombDropperComponent &bomb = reinterpret_cast<ECS::BombDropperComponent &>(entity.getComponentByName("BombDropper"));
  if (bomb.max >= bomb.bombs.size())
    return;
  else
    bomb.bombs.push_back(reinterpret_cast<ECS::Entity &>(this->_core.makeEntity("Bomb")));
}