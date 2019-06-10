/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Brick.hpp
*/

#ifndef BOMBERMAN_BRICK_HPP
#define BOMBERMAN_BRICK_HPP


#include "../Entity.hpp"
#include "../Ressources.hpp"

namespace ECS
{
	class Brick : public Entity {
	public:
		explicit Brick(unsigned id, Ressources &ressources);
	};
}


#endif //BOMBERMAN_BRICK_HPP
