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
		const Ressources &_ressources;
		static std::map<std::string, std::function<Entity *(const Ressources &ressources)>> _functions;

	public:
		explicit EntityFactory(const Ressources &ressources);

		std::unique_ptr<Entity> build(const std::string &name);
		std::vector<std::unique_ptr<Entity>> buildAll();
	};
}


#endif //BOMBERMAN_ENTITYFACTORY_HPP
