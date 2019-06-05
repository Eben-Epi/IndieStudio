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
		const Ressources &_ressources;
		static std::map<std::string, std::function<Component *(const Ressources &ressources, std::istream &stream)>> _functions;

	public:
		explicit ComponentFactory(const Ressources &ressources);

		std::unique_ptr<Component> build(const std::string &name, std::istream &stream) const;
	};
}


#endif //BOMBERMAN_COMPONENTFACTORY_HPP
