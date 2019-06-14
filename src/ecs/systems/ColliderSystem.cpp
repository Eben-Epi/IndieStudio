/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** ColliderSystem.cpp
*/

#include "ColliderSystem.hpp"

namespace ECS
{
	ColliderSystem::ColliderSystem(ECS::ECSCore &core) :
		System("Collider", core)
	{
	}

	void ColliderSystem::updateEntity(ECS::Entity &entity)
	{
	}
}