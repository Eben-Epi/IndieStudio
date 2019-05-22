/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Component.cpp
*/

#include "Component.hpp"

namespace ECS
{
	Component::Component(std::string &&name) :
		_name(name)
	{
	}

	std::string Component::getName() const
	{
		return this->_name;
	}
}