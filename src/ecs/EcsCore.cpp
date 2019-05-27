/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** EcsCore.cpp
*/

#include <iostream>
#include "EcsCore.hpp"
#include "Exceptions.hpp"

namespace ECS
{
	ECSCore::ECSCore(const ECS::Ressources &ressources) :
		_ressources(ressources),
		_systemFactory(*this),
		_entityFactory(ressources)
	{
	}

	Entity &ECSCore::getEntityById(unsigned id)
	{
		for (auto &entity : this->_entities)
			if (entity->getId() == id)
				return *entity;
		throw NoSuchEntity("Cannot find any entity with id " + std::to_string(id));
	}

	System &ECSCore::getSystem(const std::string &name)
	{
		for (auto &system : this->_systems)
			if (system->getName() == name)
				return *system;
		throw NoSuchSystem("Cannot find any system with name " + name);
	}

	std::vector<Entity *> ECSCore::getEntitiesByName(const std::string &name)
	{
		std::vector<Entity *> found;

		for (auto &entity : this->_entities)
			if (entity->getName() == name)
				found.push_back(&*entity);
		return found;
	}

	std::vector<Entity *> ECSCore::getEntitiesByComponent(const std::string &name)
	{
		std::vector<Entity *> found;

		for (auto &entity : this->_entities)
			if (entity->hasComponent(name))
				found.push_back(&*entity);
		return found;
	}

	void ECSCore::update()
	{
		for (auto &entity : this->_entities) {
			for (auto &comp : entity->getComponents()) {
				try {
					this->getSystem(comp->getName()).updateEntity(*entity);
				} catch (NoSuchSystem &e) {
					std::cerr << e.what() << ", but is required by a component of entity n°";
					std::cerr << std::to_string(entity->getId());
					std::cerr << " '" + entity->getName() + "'";
					std::cerr << std::endl;
					throw;
				}
			}
		}
	}
}