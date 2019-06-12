/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** OOBKillSystem.hpp
*/
#ifndef BOMBERMAN_OOBKILLSYSTEM_HPP
#define BOMBERMAN_OOBKILLSYSTEM_HPP

#include "../System.hpp"

namespace ECS {
    class OOBKillSystem : public System {
    public:
        OOBKillSystem(ECSCore &core);
        void updateEntity(Entity &entity) override;
    };
}


#endif //BOMBERMAN_OOBKILLSYSTEM_HPP
