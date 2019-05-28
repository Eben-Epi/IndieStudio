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
    protected:
        std::vector<std::string> _dependencies = {"Health"};
    public:
        void updateEntity(Entity &entity) override;
    };
}


#endif //BOMBERMAN_EPHEMERALSYSTEM_HPP
