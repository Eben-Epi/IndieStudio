/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** PickableSystem.hpp
*/

#ifndef BOMBERMAN_PICKABLESYSTEM_HPP
#define BOMBERMAN_PICKABLESYSTEM_HPP


#include "../System.hpp"

namespace ECS {
    class PickableSystem : public System {
    public:
        PickableSystem(ECSCore &core);
        void updateEntity(Entity &entity) override;
    };
}

#endif //BOMBERMAN_PICKABLESYSTEM_HPP
