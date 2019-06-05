/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** BombDropperSystem.hpp
*/

#ifndef BOMBERMAN_BOMBDROPPERSYSTEM_HPP
#define BOMBERMAN_BOMBDROPPERSYSTEM_HPP

#include "../System.hpp"
#include "../Components/BombDropperComponent.hpp"
#include "../Entities/Bomb.hpp"

namespace ECS {
    class BombDropperSystem : public System {
    public:
        BombDropperSystem(ECSCore &core);
        void updateEntity(Entity &entity) override;
    };
}


#endif //BOMBERMAN_BOMBDROPPERSYSTEM_HPP
