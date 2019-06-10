/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** EntityDropperSystem.hpp
*/

#ifndef BOMBERMAN_ITEMDROPPERSYSTEM_HPP
#define BOMBERMAN_ITEMDROPPERSYSTEM_HPP

#include "../System.hpp"

namespace ECS {
    class EntityDropperSystem : public System {
    public:
        EntityDropperSystem(ECSCore &);

        void updateEntity(Entity &entity) override;
    };
}


#endif //BOMBERMAN_ITEMDROPPERSYSTEM_HPP
