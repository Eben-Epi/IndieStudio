/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** PositionComponent.cpp
*/

#include "PositionComponent.hpp"

namespace ECS
{
	PositionComponent::PositionComponent(IndieStudio::PointF pos, IndieStudio::Vector2<unsigned int> size) :
		Component("Position"),
		pos(pos),
		size(size)
	{
	}
}