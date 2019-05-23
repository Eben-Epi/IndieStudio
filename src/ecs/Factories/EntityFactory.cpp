/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** EntityFactory.cpp
*/

#include "EntityFactory.hpp"

namespace ECS
{
	std::map<std::string, std::function<Entity *()>> EntityFactory::functions = {

	};

	std::unique_ptr<Entity> EntityFactory::build(std::string &&name)
	{
		return std::unique_ptr<Entity>(EntityFactory::functions[name]());
	}

	std::vector<std::unique_ptr<Entity>> EntityFactory::buildAll()
	{
		std::vector<std::unique_ptr<Entity>> vec{EntityFactory::functions.size()};

		for (auto &fun : EntityFactory::functions)
			vec.emplace_back(fun.second());
		return vec;
	}
}