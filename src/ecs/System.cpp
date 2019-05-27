/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** System.cpp
*/

#include "System.hpp"

namespace ECS
{
	System::System(std::string &&name, const ECSCore &core) :
		_name(name),
		_core(core)
	{
	}

	std::string System::getName() const
	{
		return this->_name;
	}
}