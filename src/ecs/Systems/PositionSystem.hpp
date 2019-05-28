/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** PositionSystem.hpp
*/
#ifndef BOMBERMAN_POSITIONSYSTEM_HPP
#define BOMBERMAN_POSITIONSYSTEM_HPP

#include "../System.hpp"

namespace ECS {
    class PositionSystem : public System {
    public:
	    PositionSystem(ECSCore &core);
        void updateEntity(Entity &entity) override;
    };
}


#endif //BOMBERMAN_POSITIONSYSTEM_HPP
