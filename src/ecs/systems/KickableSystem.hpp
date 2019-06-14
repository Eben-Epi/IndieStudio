/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** KickableComponent.hpp
*/
#ifndef BOMBERMAN_KICKABLESYSTEM_HPP
#define BOMBERMAN_KICKABLESYSTEM_HPP

#include "../System.hpp"

namespace ECS {
    class KickableSystem : public System {
    public:
        explicit KickableSystem(ECSCore &);

        void updateEntity(Entity &entity) override;
    };
}

#endif //BOMBERMAN_KICKABLESYSTEM_HPP
