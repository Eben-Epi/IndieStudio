/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** BlockSystem.hpp
*/
#ifndef BOMBERMAN_BLOCKSYSTEM_HPP
#define BOMBERMAN_BLOCKSYSTEM_HPP

#include "../System.hpp"

namespace ECS {
    class BlockSystem : public System {
    public:
        BlockSystem(ECSCore &core);
        void updateEntity(Entity &entity) override;
    };
}


#endif //BOMBERMAN_BLOCKSYSTEM_HPP
