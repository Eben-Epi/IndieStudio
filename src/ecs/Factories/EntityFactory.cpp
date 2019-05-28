/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** EntityFactory.cpp
*/

#include "EntityFactory.hpp"
#include "../Ressources.hpp"

namespace ECS
{
	EntityFactory::EntityFactory(const ECS::Ressources &ressources) :
		_ressources(ressources)
	{
	}

	std::map<std::string, std::function<Entity *(const Ressources &ressources)>> EntityFactory::_functions = {

	};

	std::unique_ptr<Entity> EntityFactory::build(const std::string &name) const
	{
		return std::unique_ptr<Entity>(EntityFactory::_functions[name](this->_ressources));
	}

	std::vector<std::unique_ptr<Entity>> EntityFactory::buildAll() const
	{
		std::vector<std::unique_ptr<Entity>> vec{EntityFactory::_functions.size()};

		for (auto &fun : EntityFactory::_functions)
			vec.emplace_back(fun.second(this->_ressources));
		return vec;
	}
}