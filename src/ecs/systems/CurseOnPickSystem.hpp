/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** CurseOnPickSystem.hpp
*/
#ifndef BOMBERMAN_CURSEONPICKSYSTEM_HPP
#define BOMBERMAN_CURSEONPICKSYSTEM_HPP

#include "../System.hpp"

namespace ECS {
    class CurseOnPickSystem : public System {
    public:
        CurseOnPickSystem(ECSCore &core);
        void updateEntity(Entity &entity) override;
    };
}


#endif //BOMBERMAN_CURSEONPICKSYSTEM_HPP
