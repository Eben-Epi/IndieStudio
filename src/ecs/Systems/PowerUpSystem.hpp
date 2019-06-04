/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** PowerUpSystem.hpp
*/
#ifndef BOMBERMAN_POWERUPSYSTEM_HPP
#define BOMBERMAN_POWERUPSYSTEM_HPP


#include "../System.hpp"

namespace ECS {
    class PowerUpSystem : public System {
    public:
        PowerUpSystem(ECSCore &core);
        void updateEntity(Entity &entity) override;
    };
}


#endif //BOMBERMAN_POWERUPSYSTEM_HPP
