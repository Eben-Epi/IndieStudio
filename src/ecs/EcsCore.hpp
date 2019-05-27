/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** EcsCore.hpp
*/

#ifndef BOMBERMAN_ECSCORE_HPP
#define BOMBERMAN_ECSCORE_HPP


#include <memory>
#include "System.hpp"
#include "Ressources.hpp"
#include "Factories/EntityFactory.hpp"
#include "Factories/SystemFactory.hpp"

namespace ECS
{
	class ECSCore {
	private:
		Ressources				_ressources;
		SystemFactory				_systemFactory;
		EntityFactory				_entityFactory;
		std::vector<std::unique_ptr<System>>	_systems;
		std::vector<std::unique_ptr<Entity>>	_entities;

	public:
		explicit ECSCore(const Ressources &ressources);
		Entity &getEntity(unsigned id);
		std::vector<Entity *> getEntities(const std::string &name);
		System &getSystem(const std::string &name);
		void update();
	};
}

#endif //BOMBERMAN_ECSCORE_HPP
