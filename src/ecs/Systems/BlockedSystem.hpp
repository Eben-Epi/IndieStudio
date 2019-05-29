/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** BlockedSytem.hpp
*/
#ifndef BOMBERMAN_BlockedSytem_HPP
#define BOMBERMAN_BlockedSytem_HPP

#include "../System.hpp"

namespace ECS {
    class BlockedSytem : public System {
    public:
        BlockedSytem(ECSCore &core);
        void updateEntity(Entity &entity) override;
    };
}


#endif //BOMBERMAN_BlockedSytem_HPP
