/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** ControllableSystem.hpp
*/

#ifndef BOMBERMAN_CONTROLLABLESYSTEM_HPP
#define BOMBERMAN_CONTROLLABLESYSTEM_HPP

#include "../System.hpp"

namespace ECS
{
	class ControllableSystem : public System {
	public:
		ControllableSystem(ECSCore &core);
		void updateEntity(Entity &entity) override;
	};
}


#endif //BOMBERMAN_CONTROLLABLESYSTEM_HPP
