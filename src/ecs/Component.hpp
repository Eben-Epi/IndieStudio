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
		std::string		getName() const;
		virtual std::ostream	&serialize(std::ostream &stream) const = 0;
	};
}


#endif //BOMBERMAN_COMPONENT_HPP
