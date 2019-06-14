/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Component.cpp
*/

#include <iostream>
#include "Component.hpp"
#include "Exceptions.hpp"

namespace ECS
{
	Component::Component(std::string &&name) :
		_name(name)
	{
		for (char c : name)
			if (isspace(c))
				throw InvalidNameException("Invalid name: " + name);
	}

	std::string Component::getName() const
	{
		return this->_name;
	}
}

std::ostream	&operator<<(std::ostream &stream, const ECS::Component &component)
{
	return component.serialize(stream);
}