/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** SystemFactory.cpp
*/

#include "SystemFactory.hpp"

namespace ECS
{
	std::map<std::string, std::function<System *()>> SystemFactory::functions = {

	};

	std::unique_ptr<System> SystemFactory::build(std::string &&name)
	{
		return std::unique_ptr<System>(SystemFactory::functions[name]());
	}

	std::vector<std::unique_ptr<System>> SystemFactory::buildAll()
	{
		std::vector<std::unique_ptr<System>> vec{SystemFactory::functions.size()};

		for (auto &fun : SystemFactory::functions)
			vec.emplace_back(fun.second());
		return vec;
	}
}