/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** SystemFactory.cpp
*/

#include "SystemFactory.hpp"

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
		return std::unique_ptr<System>(SystemFactory::_functions[name](this->_core));
	}

	std::vector<std::unique_ptr<System>> SystemFactory::buildAll() const
	{
		std::vector<std::unique_ptr<System>> vec{SystemFactory::_functions.size()};

		for (auto &fun : SystemFactory::_functions)
			vec.emplace_back(fun.second(this->_core));
		return vec;
	}
}