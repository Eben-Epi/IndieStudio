/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** UltStrikeSystem.hpp
*/
#ifndef BOMBERMAN_ULTSTRIKESYSTEM_HPP
#define BOMBERMAN_ULTSTRIKESYSTEM_HPP

#include "../System.hpp"

namespace ECS {
    class UltStrikeSystem : public System {
    public:
        UltStrikeSystem(ECSCore &core);
        void updateEntity(Entity &entity) override;
    };
}


#endif //BOMBERMAN_ULTSTRIKESYSTEM_HPP
