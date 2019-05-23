/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** PositionComponent.hpp
*/

#ifndef POSITIONCOMPONENT_HPP
#define POSITIONCOMPONENT_HPP

#include "../Component.hpp"
#include "../data/Vector2.hpp"

namespace ECS
{
	class PositionComponent : public Component {
	public:
		Point pos;
		PositionComponent(Point pos);
	};
} // namespace ECS

#endif