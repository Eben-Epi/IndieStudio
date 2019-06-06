/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** MortalSystem.hpp
*/

#ifndef BOMBERMAN_MORTALSYSTEM_HPP
#define BOMBERMAN_MORTALSYSTEM_HPP


#include "../System.hpp"

namespace ECS
{
	class MortalSystem : public System {
	public:
		MortalSystem(ECSCore &core);
		void updateEntity(Entity &entity) override;
	};
}


#endif //BOMBERMAN_MORTALSYSTEM_HPP
