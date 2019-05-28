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
		IndieStudio::PointF pos;
		IndieStudio::Vector2<unsigned int> size;
		PositionComponent(IndieStudio::PointF pos, IndieStudio::Vector2<unsigned int> size);
	};
} // namespace ECS

#endif