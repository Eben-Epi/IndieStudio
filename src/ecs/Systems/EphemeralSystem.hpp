/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** EphemeralSystem.hpp
*/

#ifndef BOMBERMAN_EPHEMERALSYSTEM_HPP
#define BOMBERMAN_EPHEMERALSYSTEM_HPP

#include "../System.hpp"

namespace ECS {
    class EphemeralSystem : public System {
    public:
        EphemeralSystem(ECSCore &core);
        void updateEntity(Entity &entity) override;
    };
}


#endif //BOMBERMAN_EPHEMERALSYSTEM_HPP
