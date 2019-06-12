/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** EntityFactory.cpp
*/

#include "EntityFactory.hpp"
#include "../Exceptions.hpp"
#include "../Ressources.hpp"
#include "../entities/Brick.hpp"
#include "../entities/Wall.hpp"
#include "../entities/Player.hpp"
#include "../entities/Bomb.hpp"
#include "../entities/ExplosionFrame.hpp"
#include "../entities/DroppedItem.hpp"
#include "../entities/DroppedBonusBomb.hpp"
#include "../entities/DroppedBonusHardness.hpp"
#include "../entities/DroppedBonusHealth.hpp"
#include "../entities/DroppedBonusKick.hpp"
#include "../entities/DroppedBonusSpeed.hpp"
#include "../entities/DroppedBonusRange.hpp"
#include "../entities/Bedrock.hpp"
#include "../entities/AIPlayer.hpp"
#include "../entities/Skull.hpp"

namespace ECS
{
	EntityFactory::EntityFactory(ECS::Ressources &ressources) :
		_ressources(ressources)
	{
	}

	std::map<std::string, std::function<Entity *(Ressources &ressources, unsigned id)>> EntityFactory::_functions = {
		{"AIPlayer", [](Ressources &ressources, unsigned id) { return new AIPlayer(id, ressources); }},
		{"Bomb", [](Ressources &ressources, unsigned id) { return new Bomb(id, ressources); }},
		{"Brick", [](Ressources &ressources, unsigned id) { return new Brick(id, ressources); }},
		{"DroppedBonusBomb", [](Ressources &ressources, unsigned id) { return new DroppedBonusBomb(id, ressources); }},
		{"DroppedBonusHardness", [](Ressources &ressources, unsigned id) { return new DroppedBonusHardness(id, ressources); }},
		{"DroppedBonusHealth", [](Ressources &ressources, unsigned id) { return new DroppedBonusHealth(id, ressources); }},
		{"DroppedBonusKick", [](Ressources &ressources, unsigned id) { return new DroppedBonusKick(id, ressources); }},
		{"DroppedBonusRange", [](Ressources &ressources, unsigned id) { return new DroppedBonusRange(id, ressources); }},
		{"DroppedBonusSpeed", [](Ressources &ressources, unsigned id) { return new DroppedBonusSpeed(id, ressources); }},
        {"Skull", [](Ressources &ressources, unsigned id) { return new Skull(id, ressources); }},
		{"ExplosionFrame", [](Ressources &ressources, unsigned id) { return new ExplosionFrame(id, ressources); }},
		{"Player", [](Ressources &ressources, unsigned id) { return new Player(id, ressources); }},
		{"Wall", [](Ressources &ressources, unsigned id) { return new Wall(id, ressources); }},
		{"Bedrock", [](Ressources &ressources, unsigned id) { return new Bedrock(id, ressources); }}
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