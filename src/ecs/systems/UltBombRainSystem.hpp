/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** UltBombRainSystem.hpp
*/
#ifndef BOMBERMAN_ULTBOMBRAINSYSTEM_HPP
#define BOMBERMAN_ULTBOMBRAINSYSTEM_HPP

#include "../System.hpp"

namespace ECS {
    class UltBombRainSystem : public System {
    public:
        UltBombRainSystem(ECSCore &core);
        void updateEntity(Entity &entity) override;
    };
}


#endif //BOMBERMAN_ULTBOMBRAINSYSTEM_HPP
