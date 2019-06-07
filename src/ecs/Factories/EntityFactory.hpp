/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** EntityFactory.hpp
*/

#ifndef BOMBERMAN_ENTITYFACTORY_HPP
#define BOMBERMAN_ENTITYFACTORY_HPP


#include <map>
#include <memory>
#include <functional>
#include "../Entity.hpp"
#include "../Ressources.hpp"

namespace ECS
{
	class EntityFactory {
	private:
		Ressources &_ressources;
		static std::map<std::string, std::function<Entity *(Ressources &ressources, unsigned id)>> _functions;

	public:
		explicit EntityFactory(Ressources &ressources);

		std::unique_ptr<Entity> build(const std::string &name, unsigned id) const;
		std::vector<std::unique_ptr<Entity>> buildAll(unsigned startId) const;
	};
}


#endif //BOMBERMAN_ENTITYFACTORY_HPP
