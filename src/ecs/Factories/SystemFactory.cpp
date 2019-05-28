/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** SystemFactory.cpp
*/

#include "SystemFactory.hpp"
#include "../Exceptions.hpp"

namespace ECS
{
	SystemFactory::SystemFactory(const ECS::ECSCore &core) :
		_core(core)
	{
	}

	std::map<std::string, std::function<System *(const ECS::ECSCore &core)>> SystemFactory::_functions = {

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

		for (auto &fun : SystemFactory::_functions)
			vec.emplace_back(fun.second(this->_core));
		return vec;
	}
}