/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Gunguy.hpp
*/

#ifndef BOMBERMAN_GUNGUY_HPP
#define BOMBERMAN_GUNGUY_HPP


#include "../Ressources.hpp"
#include "Player.hpp"

namespace ECS
{
	class Gunguy : public Player {
	public:
		Gunguy(unsigned id, Ressources &ressources);
	};
}


#endif //BOMBERMAN_GUNGUY_HPP
