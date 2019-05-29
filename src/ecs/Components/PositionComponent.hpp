/*
** EPITECH PROJECT, 2019
** ECS
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
		ECS::PointF pos;
		ECS::Vector2<unsigned int> size;
		PositionComponent(ECS::PointF pos, ECS::Vector2<unsigned int> size);
	};
} // namespace ECS

#endif