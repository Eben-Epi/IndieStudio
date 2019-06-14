/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** ColliderSystem.hpp
*/

#ifndef BOMBERMAN_COLLIDERSYSTEM_HPP
#define BOMBERMAN_COLLIDERSYSTEM_HPP

#include "../System.hpp"

namespace ECS
{
	class ColliderSystem : public System {
	public:
		ColliderSystem(ECSCore &core);
		void updateEntity(Entity &entity) override;
	};
}


#endif //BOMBERMAN_COLLIDERSYSTEM_HPP
