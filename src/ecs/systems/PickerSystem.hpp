/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** PickerSystem.hpp
*/

#ifndef BOMBERMAN_PICKERSYSTEM_HPP
#define BOMBERMAN_PICKERSYSTEM_HPP


#include "../System.hpp"

namespace ECS {
    class PickerSystem : public System {
    public:
        PickerSystem(ECSCore &core);
        void updateEntity(Entity &entity) override;
    };
}


#endif //BOMBERMAN_PICKERSYSTEM_HPP
