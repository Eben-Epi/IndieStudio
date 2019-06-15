/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** OwnerSystem.hpp
*/
#ifndef BOMBERMAN_OWNERSYSTEM_HPP
#define BOMBERMAN_OWNERSYSTEM_HPP

#include "../System.hpp"

namespace ECS {
    class OwnerSystem : public System {
    public:
        OwnerSystem(ECSCore &core);
        void updateEntity(Entity &entity) override;
    };
}


#endif //BOMBERMAN_OWNERSYSTEM_HPP
