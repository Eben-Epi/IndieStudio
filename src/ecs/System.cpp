/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** System.cpp
*/

#include "System.hpp"

namespace ECS
{
	System::System(std::string &&name) :
		_name(name)
	{
	}

	std::string System::getName() const
	{
		return this->_name;
	}
}