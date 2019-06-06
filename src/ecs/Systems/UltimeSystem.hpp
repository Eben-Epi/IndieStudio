/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** UltimeSystem.hpp
*/
#ifndef BOMBERMAN_ULTIMESYSTEM_HPP
#define BOMBERMAN_ULTIMESYSTEM_HPP

#include "../System.hpp"

#define ULTIME_POINT_PER_FRAME (60 / FRAME_RATE)

namespace ECS {
    class UltimeSystem : public System {
    public:
        UltimeSystem(ECSCore &core);
        void updateEntity(Entity &entity) override;
    };
}


#endif //BOMBERMAN_ULTIMESYSTEM_HPP
