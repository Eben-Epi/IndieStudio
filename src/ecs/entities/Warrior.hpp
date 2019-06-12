/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Warrior.hpp
*/

#ifndef BOMBERMAN_WARRIOR_HPP
#define BOMBERMAN_WARRIOR_HPP


#include "../Ressources.hpp"
#include "Player.hpp"

namespace ECS
{
	class Warrior : public Player {
	public:
		Warrior(unsigned id, Ressources &ressources);
	};
}


#endif //BOMBERMAN_WARRIOR_HPP
