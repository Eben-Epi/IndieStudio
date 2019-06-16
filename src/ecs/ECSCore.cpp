/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** ECSCore.cpp
*/

#include <iostream>
#include <algorithm>
#include "ECSCore.hpp"
#include "Exceptions.hpp"

namespace ECS
{
	ECSCore::ECSCore(ECS::Ressources &ressources) :
		_ressources(ressources),
		_systemFactory(*this),
		_entityFactory(ressources),
		_lastEntityId(0)
	{
		this->_systems = this->_systemFactory.buildAll();
	}

	ECSCore::ECSCore(ECS::Ressources &ressources, std::istream &stream) :
		ECSCore(ressources)
	{
		std::string value;

		stream >> value;
		if (value != "SerializedECSCore")
			throw InvalidSerializedStringException("Core header is invalid");
		for (stream >> value; value != "EndOfRecord"; stream >> value) {
			if (value != "Entity")
				throw InvalidSerializedStringException("Entity header is invalid");

			auto entity = new Entity{ressources, stream};

			try {
				this->getEntityById(entity->getId());
				throw InvalidSerializedStringException("Two entities have the same ID");
			} catch (NoSuchEntityException &) {}
			if (entity->getId() >= this->_lastEntityId)
				this->_lastEntityId = entity->getId() + 1;
			this->_entities.emplace_back(entity);
			for (auto &comp : this->_entities.back()->getComponents())
				this->_components[comp->getName()].push_back(&*this->_entities.back());
		}
	}

	Entity &ECSCore::getEntityById(unsigned id) const
	{
		for (auto &entity : this->_entities)
			if (entity && entity->getId() == id)
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
			if (entity && entity->getName() == name)
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
		if (this->_destroyed.empty()) {
			this->_entities.push_back(this->_entityFactory.build(name,this->_lastEntityId++));
			for (auto &comp : this->_entities.back()->getComponents())
				this->_components[comp->getName()].push_back(&*this->_entities.back());
			return *this->_entities.back();
		}
		auto value = this->_entityFactory.build(name,this->_lastEntityId++);

		this->_entities[this->_destroyed.front()].swap(value);

		Entity &entity = *this->_entities[this->_destroyed.front()];

		for (auto &comp : entity.getComponents())
			this->_components[comp->getName()].push_back(&entity);
		this->_destroyed.erase(this->_destroyed.begin());
		return entity;
	}

	void ECSCore::update()
	{
		for (size_t i = 0; i < this->_entities.size(); i++) {
			auto &entity = this->_entities[i];

			if (!entity)
				continue;
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
		for (auto it = this->_entities.begin(); it < this->_entities.end(); it++) {
			while (it < this->_entities.end() && *it && (*it)->isDestroyed()) {
				for (auto &comp : (*it)->getComponents())
					this->_components[comp->getName()].erase(
						std::find(
							this->_components[comp->getName()].begin(),
							this->_components[comp->getName()].end(),
							&**it
						)
					);
				this->_destroyed.push_back(it - this->_entities.begin());
				it->reset(nullptr);
			}
		}
	}

	std::ostream& ECSCore::serialize(std::ostream &stream) const
	{
		stream << "SerializedECSCore" << std::endl;
		for (auto &entity : this->_entities)
			if (entity)
				stream << "Entity " << *entity << std::endl;
		return stream << "EndOfRecord";
	}
}

std::ostream &operator<<(std::ostream &stream, const ECS::ECSCore &core)
{
	return core.serialize(stream);
}