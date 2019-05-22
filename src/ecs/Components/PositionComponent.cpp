/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** PositionComponent.cpp
*/

#include "PositionComponent.hpp"

namespace ECS
{
	Position::Position(Point pos)
	: Component("Position")
	{
		this->_pos = pos;
	}
}