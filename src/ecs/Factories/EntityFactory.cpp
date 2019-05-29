/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** EntityFactory.cpp
*/

#include "EntityFactory.hpp"
#include "../Exceptions.hpp"
#include "../Ressources.hpp"
#include "../Entities/Brick.hpp"
#include "../Entities/Wall.hpp"

namespace ECS
{
	EntityFactory::EntityFactory(const ECS::Ressources &ressources) :
		_ressources(ressources)
	{
	}

	std::map<std::string, std::function<Entity *(const Ressources &ressources, unsigned id)>> EntityFactory::_functions = {
		{"Brick", [](const Ressources &ressources, unsigned id) { return new Brick(id, ressources); }},
		{"Wall", [](const Ressources &ressources, unsigned id) { return new Wall(id, ressources);}}
	};

	std::unique_ptr<Entity> EntityFactory::build(const std::string &name, unsigned id) const
	{
		try {
			return std::unique_ptr<Entity>(EntityFactory::_functions[name](this->_ressources, id));
		} catch (std::bad_function_call &) {
			throw NoSuchEntityException("Cannot build entity called " + name);
		}
	}

	std::vector<std::unique_ptr<Entity>> EntityFactory::buildAll(unsigned startId) const
	{
		std::vector<std::unique_ptr<Entity>> vec{EntityFactory::_functions.size()};

		for (auto &fun : EntityFactory::_functions)
			vec.emplace_back(fun.second(this->_ressources, startId++));
		return vec;
	}
}