/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** ExplodeSystem.hpp
*/
#ifndef BOMBERMAN_EXPLODESYSTEM_HPP
#define BOMBERMAN_EXPLODESYSTEM_HPP


#include "../System.hpp"

namespace ECS {
    enum ExplosionObstructionLocation {
        NO_OBS,
        WEST_OBS,
        EAST_OBS,
        NORTH_OBS,
        SOUTH_OBS
    };

    class ExplodeSystem : public System {
    public:
        ExplodeSystem(ECSCore &core);
        void updateEntity(Entity &entity) override;
    };
}


#endif //BOMBERMAN_EXPLODESYSTEM_HPP