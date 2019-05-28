/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** CollisionSystem.hpp
*/

#ifndef BOMBERMAN_COLLISIONSYSTEM_HPP
#define BOMBERMAN_COLLISIONSYSTEM_HPP

#include "../System.hpp"

namespace ECS {
    class CollisionSystem : public System {
    public:
	    CollisionSystem(ECSCore &core);
        void updateEntity(Entity &entity) override;
    };
}


#endif //BOMBERMAN_COLLISIONSYSTEM_HPP
