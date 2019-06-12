/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Faerie.hpp
*/

#ifndef BOMBERMAN_FAERIE_HPP
#define BOMBERMAN_FAERIE_HPP


#include "../Ressources.hpp"
#include "Player.hpp"

namespace ECS
{
	class Faerie : public Player {
	public:
		Faerie(unsigned id, Ressources &ressources);
	};
}


#endif //BOMBERMAN_FAERIE_HPP
