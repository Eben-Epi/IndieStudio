/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Colision.hpp
*/

#ifndef DIRECTIONCOMPONENT_HPP
#define DERECTIONCOMPONENT_HPP

#include "../Component.hpp"
#include "../data/Directions.hpp"

namespace ECS
{
	class DirectionComponent : public Component {
	public:
		IndieStudio::Directions dir;
		DirectionComponent();
	};
} // namespace ECS

#endif