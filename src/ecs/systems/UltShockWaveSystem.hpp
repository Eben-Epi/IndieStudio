/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** UltShockWaveSystem.hpp
*/
#ifndef BOMBERMAN_ULTSHOCKWAVESYSTEM_HPP
#define BOMBERMAN_ULTSHOCKWAVESYSTEM_HPP

#include "../System.hpp"

namespace ECS {
    class UltShockWaveSystem : public System {
    public:
        UltShockWaveSystem(ECSCore &core);
        void updateEntity(Entity &entity) override;
    };
}


#endif //BOMBERMAN_ULTSHOCKWAVESYSTEM_HPP
