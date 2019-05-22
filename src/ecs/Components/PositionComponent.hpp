/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** PositionComponent.hpp
*/

#ifndef POSITIONCOMPONENT_HPP
#define POSITIONCOMPONENT_HPP

#include "Component.hpp"

namespace ECS
{
	class Position : public Component {
		public:
			Point _pos;
			Position(Point pos);
	};
} // namespace ECS

#endif