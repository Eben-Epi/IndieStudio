/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** ECSCore.hpp
*/

#ifndef BOMBERMAN_ECSCORE_HPP
#define BOMBERMAN_ECSCORE_HPP


#include <memory>
#include "System.hpp"
#include "Ressources.hpp"
#include "factories/EntityFactory.hpp"
#include "factories/SystemFactory.hpp"

namespace ECS
{
	class ECSCore {
	private:
		unsigned					_lastEntityId;
		Ressources					&_ressources;
		SystemFactory					_systemFactory;
		EntityFactory					_entityFactory;
		std::vector<std::unique_ptr<System>>		_systems;
		std::vector<std::unique_ptr<Entity>>		_entities;
		std::vector<unsigned>				_destroyed;
		std::map<std::string, std::vector<Entity *>>	_components;

	public:
		explicit ECSCore(Ressources &ressources);
		explicit ECSCore(Ressources &ressources, std::istream &stream);
		Entity &getEntityById(unsigned id) const;
		std::vector<Entity *> getEntitiesByName(const std::string &name) const;
		std::vector<Entity *> getEntitiesByComponent(const std::string &name) const;
		System &getSystem(const std::string &name) const;
		Entity &makeEntity(const std::string &name);
		std::ostream &serialize(std::ostream &stream) const;
		void update();
	};
}

std::ostream &operator<<(std::ostream &stream, const ECS::ECSCore &core);


#endif //BOMBERMAN_ECSCORE_HPP
