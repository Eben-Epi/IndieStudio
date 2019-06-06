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
#include "../Component.hpp"
#include "../Ressources.hpp"

namespace ECS
{
	class ComponentFactory {
	private:
		Ressources &_ressources;
		static std::map<std::string, std::function<Component *(Ressources &ressources, std::istream &stream)>> _functions;

	public:
		explicit ComponentFactory(Ressources &ressources);

		std::unique_ptr<Component> build(const std::string &name, std::istream &stream) const;
	};
}


#endif //BOMBERMAN_COMPONENTFACTORY_HPP
