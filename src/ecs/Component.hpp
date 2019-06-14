/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Component.hpp
*/

#ifndef BOMBERMAN_COMPONENT_HPP
#define BOMBERMAN_COMPONENT_HPP

#include <string>

namespace ECS
{
	class Component {
	private:
		std::string	_name;

	public:
		Component(std::string &&name);
		virtual ~Component() = default;
		std::string		getName() const;
		virtual std::ostream	&serialize(std::ostream &stream) const = 0;
	};
}

std::ostream	&operator<<(std::ostream &stream, const ECS::Component &component);


#endif //BOMBERMAN_COMPONENT_HPP
