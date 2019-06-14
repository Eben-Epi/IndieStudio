/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** MovableSystem.hpp
*/
#ifndef BOMBERMAN_MOVABLESYSTEM_HPP
#define BOMBERMAN_MOVABLESYSTEM_HPP

#include "../System.hpp"

namespace ECS {
    class MovableSystem : public System {
    public:
	    MovableSystem(ECSCore &core);
        void updateEntity(Entity &entity) override;
    };
}


#endif //BOMBERMAN_MOVABLESYSTEM_HPP
