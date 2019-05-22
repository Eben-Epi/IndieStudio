/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Entity.cpp
*/

#include "Entity.hpp"

namespace ECS
{
	Entity::Entity(unsigned id, std::string &&name, std::vector<Component> &&components) :
		_id(id),
		_name(name),
		_components(components)
	{
	}
}