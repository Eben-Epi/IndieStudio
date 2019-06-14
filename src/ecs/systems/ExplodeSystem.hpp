/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** ExplodeSystem.hpp
*/
#ifndef BOMBERMAN_EXPLODESYSTEM_HPP
#define BOMBERMAN_EXPLODESYSTEM_HPP


#include "../System.hpp"
#include "../data/Vector2.hpp"

#define BETWEEN(min, value, max) (min <= value && value < max)

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
        ECS::ExplosionObstructionLocation isOnExplosionWay(std::vector<ECS::Vector2<double>> &posAndSize, ECS::Point &pos, ECS::Point BombPos);
    };
}

#endif //BOMBERMAN_EXPLODESYSTEM_HPP
