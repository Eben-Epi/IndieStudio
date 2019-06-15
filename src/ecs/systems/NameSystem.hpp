/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** NameSystem.hpp
*/

#ifndef BOMBERMAN_NAMESYSTEM_HPP
#define BOMBERMAN_NAMESYSTEM_HPP

#include "../System.hpp"

namespace ECS {
    class NameSystem : public System {
    public:
        NameSystem(ECSCore &core);
        void updateEntity(Entity &entity) override;
    };
}


#endif //BOMBERMAN_NAMESYSTEM_HPP
