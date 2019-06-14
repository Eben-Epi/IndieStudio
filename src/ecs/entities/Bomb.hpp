/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Bomb.hpp
*/

#ifndef BOMBERMAN_BOMB_HPP
#define BOMBERMAN_BOMB_HPP

#include "../Entity.hpp"
#include "../Ressources.hpp"

namespace ECS
{
    class Bomb : public Entity {
    public:
        explicit Bomb(unsigned id, Ressources &ressources);
    };
}


#endif //BOMBERMAN_BOMB_HPP
