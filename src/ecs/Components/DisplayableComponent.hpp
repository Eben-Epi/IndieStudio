/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Displayable.hpp
*/

#ifndef DISPLAYABLECOMPONENT_HPP
#define DISPLAYABLECOMPONENT_HPP

#include "../Component.hpp"

namespace ECS
{
	class DisplayableComponent : public Component {
	public:
		std::string	spriteId;
		unsigned	animation;
		explicit DisplayableComponent(std::string &&striteId);
	};
}

#endif