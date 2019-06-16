/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Player.hpp
*/

#ifndef BOMBERMAN_PLAYER_HPP
#define BOMBERMAN_PLAYER_HPP


#include "../Entity.hpp"
#include "../Ressources.hpp"

namespace ECS
{
	class Player : public Entity {
	public:
		explicit Player(unsigned id, Ressources &ressources, std::string &&texture, Component *ultimate, const std::string &name);
	};
}


#endif //BOMBERMAN_PLAYER_HPP
