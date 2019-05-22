/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Entity.hpp
*/

#ifndef BOMBERMAN_ENTITY_HPP
#define BOMBERMAN_ENTITY_HPP


#include <vector>
#include "Component.hpp"

namespace ECS
{
	class Entity {
	private:
		unsigned		_id;
		std::string		_name;
		std::vector<Component>	_components;

	public:
		Entity(unsigned id, std::string &&name, std::vector<Component> &&components);
		unsigned		getId() const;
		std::string		getName() const;
		std::vector<Component>	&getComponents();
		Component		&getComponentByName(std::string name) const;
	};
}


#endif //BOMBERMAN_ENTITY_HPP
