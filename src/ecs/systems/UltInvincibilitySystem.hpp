/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** UltInvincibilitySystem.hpp
*/
#ifndef BOMBERMAN_ULTINVINCIBILITYSYSTEM_HPP
#define BOMBERMAN_ULTINVINCIBILITYSYSTEM_HPP

#include "../System.hpp"

namespace ECS {
    class UltInvincibilitySystem : public System {
    public:
        UltInvincibilitySystem(ECSCore &core);
        void updateEntity(Entity &entity) override;
    };
}


#endif //BOMBERMAN_ULTINVINCIBILITYSYSTEM_HPP
