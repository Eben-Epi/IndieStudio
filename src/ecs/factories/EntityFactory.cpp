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
#include "../entities/Bomb.hpp"
#include "../entities/ExplosionFrame.hpp"
#include "../entities/PowerUps/DroppedItem.hpp"
#include "../entities/PowerUps/DroppedBonusBomb.hpp"
#include "../entities/PowerUps/DroppedBonusHardness.hpp"
#include "../entities/PowerUps/DroppedBonusHealth.hpp"
#include "../entities/PowerUps/DroppedBonusKick.hpp"
#include "../entities/PowerUps/DroppedBonusSpeed.hpp"
#include "../entities/PowerUps/DroppedBonusRange.hpp"
#include "../entities/Bedrock.hpp"
#include "../entities/Skull.hpp"
#include "../entities/Sydney.hpp"
#include "../entities/Faerie.hpp"
#include "../entities/Alphaone.hpp"
#include "../entities/Xenotype.hpp"
#include "../entities/PowerUps/DroppedBonusGhost.hpp"

namespace ECS
{
	EntityFactory::EntityFactory(ECS::Ressources &ressources) :
		_ressources(ressources)
	{
	}

	std::map<std::string, std::function<Entity *(Ressources &ressources, unsigned id)>> EntityFactory::_functions = {
		{"Bomb", [](Ressources &ressources, unsigned id) { return new Bomb(id, ressources); }},
		{"Brick", [](Ressources &ressources, unsigned id) { return new Brick(id, ressources); }},
		{"DroppedBonusBomb", [](Ressources &ressources, unsigned id) { return new DroppedBonusBomb(id, ressources); }},
		{"DroppedBonusHardness", [](Ressources &ressources, unsigned id) { return new DroppedBonusHardness(id, ressources); }},
		{"DroppedBonusHealth", [](Ressources &ressources, unsigned id) { return new DroppedBonusHealth(id, ressources); }},
		{"DroppedBonusKick", [](Ressources &ressources, unsigned id) { return new DroppedBonusKick(id, ressources); }},
		{"DroppedBonusRange", [](Ressources &ressources, unsigned id) { return new DroppedBonusRange(id, ressources); }},
		{"DroppedBonusSpeed", [](Ressources &ressources, unsigned id) { return new DroppedBonusSpeed(id, ressources); }},
		{"DroppedBonusGhost", [](Ressources &ressources, unsigned id) { return new DroppedBonusGhost(id, ressources); }},
		{"Skull", [](Ressources &ressources, unsigned id) { return new Skull(id, ressources); }},
		{"ExplosionFrame", [](Ressources &ressources, unsigned id) { return new ExplosionFrame(id, ressources); }},
		{"Faerie", [](Ressources &ressources, unsigned id) { return new Faerie(id, ressources); }},
		{"Sydney", [](Ressources &ressources, unsigned id) { return new Sydney(id, ressources); }},
		{"Xenotype", [](Ressources &ressources, unsigned id) { return new Xenotype(id, ressources); }},
		{"Alphaone", [](Ressources &ressources, unsigned id) { return new Alphaone(id, ressources); }},
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