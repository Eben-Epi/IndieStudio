/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** SystemFactory.cpp
*/

#include "SystemFactory.hpp"
#include "../Exceptions.hpp"
#include "../Systems/HealthSystem.hpp"
#include "../Systems/CollisionSystem.hpp"
#include "../Systems/DisplayableSystem.hpp"
#include "../Systems/PositionSystem.hpp"
#include "../Systems/MovableSystem.hpp"
#include "../Systems/KickableSystem.hpp"
#include "../Systems/EphemeralSystem.hpp"
#include "../Systems/ControllableSystem.hpp"
#include "../Systems/BuffedSystem.hpp"
#include "../Systems/BombDropperSystem.hpp"

namespace ECS
{
	SystemFactory::SystemFactory(ECS::ECSCore &core) :
		_core(core)
	{
	}

	std::map<std::string, std::function<System *(ECS::ECSCore &core)>> SystemFactory::_functions = {
		{"BombDropper", [](ECS::ECSCore &core) { return new BombDropperSystem(core); }},
		{"Buffed", [](ECS::ECSCore &core) { return new BuffedSystem(core); }},
		{"Collision", [](ECS::ECSCore &core) { return new CollisionSystem(core); }},
		{"Controllable", [](ECS::ECSCore &core) { return new ControllableSystem(core); }},
		{"Displayable", [](ECS::ECSCore &core) { return new DisplayableSystem(core); }},
		{"Ephemeral", [](ECS::ECSCore &core) { return new EphemeralSystem(core); }},
		{"Health", [](ECS::ECSCore &core) { return new HealthSystem(core); }},
		{"Kickable", [](ECS::ECSCore &core) { return new KickableSystem(core); }},
		{"Movable", [](ECS::ECSCore &core) { return new MovableSystem(core); }},
		{"Position", [](ECS::ECSCore &core) { return new PositionSystem(core); }}
	};

	std::unique_ptr<System> SystemFactory::build(std::string &&name) const
	{
		try {
			return std::unique_ptr<System>(SystemFactory::_functions[name](this->_core));
		} catch (std::bad_function_call &) {
			throw NoSuchSystemException("Cannot create system called " + name);
		}
	}

	std::vector<std::unique_ptr<System>> SystemFactory::buildAll() const
	{
		std::vector<std::unique_ptr<System>> vec{SystemFactory::_functions.size()};
		int i = 0;

		for (auto &fun : SystemFactory::_functions)
			vec[i++] = std::unique_ptr<System>(fun.second(this->_core));
		return vec;
	}
}