/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Entity.hpp
*/

#ifndef BOMBERMAN_ENTITY_HPP
#define BOMBERMAN_ENTITY_HPP


#include <vector>
#include <memory>
#include "Component.hpp"

namespace ECS
{
    struct Ressources;

	class Entity {
	private:
		bool _destroy;
		unsigned _id;
		std::string _name;
		std::vector<std::unique_ptr<Component>> _components;

	public:
		Entity(unsigned id, std::string &&name, const std::vector<Component *> &&components);
		Entity(Ressources &ressources, std::istream &stream);
		void destroy();
		bool isDestroyed();
		unsigned getId() const;
		std::string getName() const;
		bool hasComponent(const std::string &name) const;
		Component &getComponentByName(const std::string &name) const;
		std::vector<std::unique_ptr<Component>> &getComponents();
		std::ostream	&serialize(std::ostream &stream) const;
	};
}

std::ostream	&operator<<(std::ostream &stream, const ECS::Entity &component);


#endif //BOMBERMAN_ENTITY_HPP
