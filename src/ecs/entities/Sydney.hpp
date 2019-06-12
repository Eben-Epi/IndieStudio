/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Sydney.hpp
*/

#ifndef BOMBERMAN_SYDNEY_HPP
#define BOMBERMAN_SYDNEY_HPP


#include "Player.hpp"

namespace ECS
{
	class Sydney : public Player {
	public:
		Sydney(unsigned id, Ressources &ressources);
	};
}


#endif //BOMBERMAN_SYDNEY_HPP
