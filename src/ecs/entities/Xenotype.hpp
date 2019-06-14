/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Warrior.hpp
*/

#ifndef BOMBERMAN_XENOTYPE_HPP
#define BOMBERMAN_XENOTYPE_HPP


#include "../Ressources.hpp"
#include "Player.hpp"

namespace ECS
{
	class Xenotype : public Player {
	public:
		Xenotype(unsigned id, Ressources &ressources);
	};
}


#endif //BOMBERMAN_WARRIOR_HPP
