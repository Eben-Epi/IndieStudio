/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** KickerSystem.hpp
*/
#ifndef BOMBERMAN_KICKERSYSTEM_HPP
#define BOMBERMAN_KICKERSYSTEM_HPP


#include "../System.hpp"

namespace ECS {
    class KickerSystem : public System {
    public:
        explicit KickerSystem(ECSCore &);
        void updateEntity(Entity &entity) override;
    };
}


#endif //BOMBERMAN_KICKERSYSTEM_HPP
