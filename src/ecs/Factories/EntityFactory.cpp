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
#include "../Entities/Player.hpp"
#include "../Entities/Bomb.hpp"
#include "../Entities/ExplosionFrame.hpp"
#include "../Entities/DroppedItem.hpp"
#include "../Entities/DroppedBonusBomb.hpp"
#include "../Entities/DroppedBonusHardness.hpp"
#include "../Entities/DroppedBonusHealth.hpp"
#include "../Entities/DroppedBonusKick.hpp"
#include "../Entities/DroppedBonusSpeed.hpp"
#include "../Entities/DroppedBonusRange.hpp"

namespace ECS
{
	EntityFactory::EntityFactory(const ECS::Ressources &ressources) :
		_ressources(ressources)
	{
	}

	std::map<std::string, std::function<Entity *(const Ressources &ressources, unsigned id)>> EntityFactory::_functions = {
		{"Bomb", [](const Ressources &ressources, unsigned id) { return new Bomb(id, ressources); }},
		{"Brick", [](const Ressources &ressources, unsigned id) { return new Brick(id, ressources); }},
		{"DroppedBonusBomb", [](const Ressources &ressources, unsigned id) { return new DroppedBonusBomb(id, ressources); }},
		{"DroppedBonusHardness", [](const Ressources &ressources, unsigned id) { return new DroppedBonusHardness(id, ressources); }},
		{"DroppedBonusHealth", [](const Ressources &ressources, unsigned id) { return new DroppedBonusHealth(id, ressources); }},
		{"DroppedBonusKick", [](const Ressources &ressources, unsigned id) { return new DroppedBonusKick(id, ressources); }},
		{"DroppedBonusRange", [](const Ressources &ressources, unsigned id) { return new DroppedBonusRange(id, ressources); }},
		{"DroppedBonusSpeed", [](const Ressources &ressources, unsigned id) { return new DroppedBonusSpeed(id, ressources); }},
		{"ExplosionFrame", [](const Ressources &ressources, unsigned id) { return new ExplosionFrame(id, ressources); }},
		{"Player", [](const Ressources &ressources, unsigned id) { return new Player(id, ressources); }},
		{"Wall", [](const Ressources &ressources, unsigned id) { return new Wall(id, ressources); }}
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