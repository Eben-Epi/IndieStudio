/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** BombDropperSystem.hpp
*/
#ifndef BOMBERMAN_BOMBDROPPERSYSTEM_HPP
#define BOMBERMAN_BOMBDROPPERSYSTEM_HPP

#include "../System.hpp"

namespace ECS {
    class BombDropperSystem : public System {
        public:
        void updateEntity(Entity &entity) override;
    };
}


#endif //BOMBERMAN_BOMBDROPPERSYSTEM_HPP
