/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** PowerUpPickedSystem.hpp
*/

#ifndef BOMBERMAN_POWERUPPICKEDSYSTEM_HPP
#define BOMBERMAN_POWERUPPICKEDSYSTEM_HPP

#include "../System.hpp"

namespace ECS {
    class PowerUpPickedSystem : public System {
    public:
        PowerUpPickedSystem(ECSCore &core);
        void updateEntity(Entity &entity) override;
    };
}

#endif //BOMBERMAN_POWERUPPICKEDSYSTEM_HPP
