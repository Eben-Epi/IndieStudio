/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** BlockedSystem.hpp
*/
#ifndef BOMBERMAN_BlockedSystem_HPP
#define BOMBERMAN_BlockedSystem_HPP

#include "../System.hpp"

namespace ECS {
    class BlockedSystem : public System {
    public:
        BlockedSystem(ECSCore &core);
        void updateEntity(Entity &entity) override;
    };
}


#endif //BOMBERMAN_BlockedSystem_HPP
