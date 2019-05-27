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

namespace ECS
{
	class EntityFactory {
	public:
		static std::map<std::string, std::function<Entity *()>> functions;

		static std::unique_ptr<Entity> build(std::string &&name);
		static std::vector<std::unique_ptr<Entity>> buildAll();
	};
}


#endif //BOMBERMAN_ENTITYFACTORY_HPP
