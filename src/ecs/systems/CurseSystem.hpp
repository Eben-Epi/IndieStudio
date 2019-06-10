/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** CurseSystem.hpp
*/
#ifndef BOMBERMAN_CURSESYSTEM_HPP
#define BOMBERMAN_CURSESYSTEM_HPP

#include "../System.hpp"

namespace ECS {
    class CurseSystem : public System {
    public:
        CurseSystem(ECSCore &core);
        void updateEntity(Entity &entity) override;
    };
}


#endif //BOMBERMAN_CURSESYSTEM_HPP
