/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** BuffedSystem.hpp
*/
#ifndef BOMBERMAN_BUFFEDSYSTEM_HPP
#define BOMBERMAN_BUFFEDSYSTEM_HPP

#include "../System.hpp"

namespace ECS {
    class BuffedSystem : public System {
    public:
    	BuffedSystem(ECSCore &core);
        void updateEntity(Entity &entity) override;
    };
}

#endif //BOMBERMAN_BUFFEDSYSTEM_HPP
