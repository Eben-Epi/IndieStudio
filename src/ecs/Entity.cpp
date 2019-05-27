/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Entity.cpp
*/

#include "Entity.hpp"
#include "Exceptions.hpp"

namespace ECS
{
	Entity::Entity(unsigned id, std::string &&name, std::vector<Component *> &&components) :
		_destroy(false),
		_id(id),
		_name(name)
	{
		for (Component *comp : components)
			this->_components.emplace_back(comp);
	}

	std::string Entity::getName() const
	{
		return this->_name;
	}

	unsigned Entity::getId() const
	{
		return this->_id;
	}

	std::vector<std::unique_ptr<Component>>& Entity::getComponents()
	{
		return this->_components;
	}

	Component &Entity::getComponentByName(const std::string &name) const
	{
		for (auto &comp : this->_components)
			if (comp->getName() == name)
				return *comp;
		throw NoSuchComponentException(this->_name + " (id: " + std::to_string(this->_id) + ") has not " + name);
	}

	bool Entity::hasComponent(const std::string &name) const
	{
		try {
			this->getComponentByName(name);
		} catch (NoSuchComponentException &) {
			return false;
		}
		return true;
	}

	bool Entity::isDestroyed()
	{
		return this->_destroy;
	}

	void Entity::destroy()
	{
		this->_destroy = true;
	}
}