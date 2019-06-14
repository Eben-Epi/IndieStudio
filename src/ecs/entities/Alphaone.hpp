/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Gunguy.hpp
*/

#ifndef BOMBERMAN_ALPHAONE_HPP
#define BOMBERMAN_ALPHAONE_HPP


#include "../Ressources.hpp"
#include "Player.hpp"

namespace ECS
{
	class Alphaone : public Player {
	public:
		Alphaone(unsigned id, Ressources &ressources);
	};
}


#endif //BOMBERMAN_GUNGUY_HPP
