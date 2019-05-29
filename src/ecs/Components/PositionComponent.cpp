/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** PositionComponent.cpp
*/

#include "PositionComponent.hpp"

namespace ECS
{
	PositionComponent::PositionComponent(ECS::PointF pos, ECS::Vector2<unsigned int> size) :
		Component("Position"),
		pos(pos),
		size(size)
	{
	}
}