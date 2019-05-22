/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Colision.hpp
*/

#ifndef DIRECTIONCOMPONENT_HPP
#define DERECTIONCOMPONENT_HPP

#include "Component.hpp"

namespace ECS
{
	class Direction : public Component {
		public:
			Directions _dir;
			Direction();
	};
} // namespace ECS

#endif