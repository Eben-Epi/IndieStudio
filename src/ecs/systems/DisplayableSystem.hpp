/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** DisplayableSystem.hpp
*/

#ifndef BOMBERMAN_DISPLAYABLESYSTEM_HPP
#define BOMBERMAN_DISPLAYABLESYSTEM_HPP

#include "../System.hpp"

namespace ECS {
    class DisplayableSystem : public System {
    public:
        DisplayableSystem(ECSCore &core);
        void updateEntity(Entity &entity) override;
    };
}


#endif //BOMBERMAN_DISPLAYABLESYSTEM_HPP
