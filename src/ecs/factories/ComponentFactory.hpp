/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** ComponentFactory.hpp
*/

#ifndef BOMBERMAN_COMPONENTFACTORY_HPP
#define BOMBERMAN_COMPONENTFACTORY_HPP


#include <memory>
#include <functional>
#include <map>
#include "../Component.hpp"
#include "../Ressources.hpp"

namespace ECS
{
	class ComponentFactory {
	private:
		Ressources &_ressources;
		static std::map<std::string, std::function<Component *(unsigned id, Ressources &ressources, std::istream &stream)>> _functions;

	public:
		explicit ComponentFactory(Ressources &ressources);

		std::unique_ptr<Component> build(const std::string &name, unsigned id, std::istream &stream) const;
	};
}


#endif //BOMBERMAN_COMPONENTFACTORY_HPP
