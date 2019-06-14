/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** NameSystem.cpp
*/

#include "NameSystem.hpp"

namespace ECS
{
	NameSystem::NameSystem(ECS::ECSCore &core) :
		System("Name", core)
	{}

	void NameSystem::updateEntity(ECS::Entity &entity)
	{}
}