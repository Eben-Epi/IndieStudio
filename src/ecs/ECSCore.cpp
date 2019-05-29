/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** ECSCore.cpp
*/

#include <iostream>
#include "ECSCore.hpp"
#include "Exceptions.hpp"

namespace ECS
{
	ECSCore::ECSCore(const ECS::Ressources &ressources) :
		_ressources(ressources),
		_systemFactory(*this),
		_entityFactory(ressources),
		_lastEntityId(0)
	{
		this->_systems = this->_systemFactory.buildAll();
	}

	Entity &ECSCore::getEntityById(unsigned id) const
	{
		for (auto &entity : this->_entities)
			if (entity->getId() == id)
				return *entity;
		throw NoSuchEntityException("Cannot find any entity with id " + std::to_string(id));
	}

	System &ECSCore::getSystem(const std::string &name) const
	{
		for (auto &system : this->_systems)
			if (system->getName() == name)
				return *system;
		throw NoSuchSystemException("Cannot find any system with name " + name);
	}

	std::vector<Entity *> ECSCore::getEntitiesByName(const std::string &name) const
	{
		std::vector<Entity *> found;

		for (auto &entity : this->_entities)
			if (entity->getName() == name)
				found.push_back(&*entity);
		return found;
	}

	std::vector<Entity *> ECSCore::getEntitiesByComponent(const std::string &name) const
	{
		try {
			return this->_components.at(name);
		} catch (std::out_of_range &) {
			return {};
		}
	}

	Entity &ECSCore::makeEntity(const std::string &name)
	{
		this->_entities.push_back(this->_entityFactory.build(name, this->_lastEntityId++));
		for (auto &comp : this->_entities.back()->getComponents())
			this->_components[comp->getName()].push_back(&*this->_entities.back());
		return *this->_entities.back();
	}

	void ECSCore::update()
	{
		for (auto &entity : this->_entities) {
			for (auto &comp : entity->getComponents()) {
				try {
					auto &system = this->getSystem(comp->getName());

					system.checkDependencies(*entity);
					system.updateEntity(*entity);
				} catch (NoSuchSystemException &e) {
					std::cerr << e.what() << ", but is required by " + comp->getName() + "Component of entity n°";
					std::cerr << std::to_string(entity->getId());
					std::cerr << " '" + entity->getName() + "'";
					std::cerr << std::endl;
					throw;
				} catch (MissingDependenciesException &e) {
					std::cerr << e.what() << ", but is required by " + comp->getName() + "Component of entity n°";
					std::cerr << std::to_string(entity->getId());
					std::cerr << " '" + entity->getName() + "'";
					std::cerr << std::endl;
					throw;
				}
			}
		}
		for (auto it = this->_entities.begin(); it < this->_entities.end(); it++)
			while ((*it)->isDestroyed())
				this->_entities.erase(it);
	}

	void ECSCore::reset()
	{
		this->_entities.erase(this->_entities.begin(), this->_entities.end());
		this->_lastEntityId = 0;
	}
}