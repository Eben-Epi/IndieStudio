/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Bedrock.hpp
*/

#ifndef BOMBERMAN_BEDROCK_HPP
#define BOMBERMAN_BEDROCK_HPP


#include "../Entity.hpp"

namespace ECS
{
	class Bedrock : public Entity {
	public:
		explicit Bedrock(unsigned id, Ressources &ressources);
	};
}


#endif //BOMBERMAN_BEDROCK_HPP
