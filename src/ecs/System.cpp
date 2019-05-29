/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** System.cpp
*/

#include "System.hpp"
#include "Exceptions.hpp"

namespace ECS
{
	System::System(std::string &&name, ECSCore &core) :
		_name(name),
		_core(core)
	{
	}

	void	System::checkDependencies(ECS::Entity &entity)
	{
		if (!entity.hasComponent(this->_name))
			throw InvalidStateException("The entity doesn't have a " + this->_name + "Component");
		for (auto &dep : this->_dependencies)
			if (!entity.hasComponent(dep))
				throw MissingDependenciesException("This entity doesn't have a " + dep + "Component");
	}

	std::string System::getName() const
	{
		return this->_name;
	}
}