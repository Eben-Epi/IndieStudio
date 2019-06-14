/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** KillCounterSystem.hpp
*/
#ifndef BOMBERMAN_KILLCOUNTERSYSTEM_HPP
#define BOMBERMAN_KILLCOUNTERSYSTEM_HPP

#include "../System.hpp"

namespace ECS {
    class KillCounterSystem : public System {
    public:
        KillCounterSystem(ECSCore &core);
        void updateEntity(Entity &entity) override;
    };
}


#endif //BOMBERMAN_KILLCOUNTERSYSTEM_HPP
