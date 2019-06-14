/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Skull.hpp
*/
#ifndef BOMBERMAN_SKULL_HPP
#define BOMBERMAN_SKULL_HPP

#include "../Ressources.hpp"
#include "../Entity.hpp"

namespace ECS {
    class Skull : public Entity {
    public:
        explicit Skull(unsigned id, Ressources &ressources);
    };
}


#endif //BOMBERMAN_SKULL_HPP
