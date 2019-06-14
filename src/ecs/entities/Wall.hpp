/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Wall.hpp
*/

#ifndef BOMBERMAN_WALL_HPP
#define BOMBERMAN_WALL_HPP


#include "../Entity.hpp"
#include "../Ressources.hpp"

namespace ECS
{
    class Wall : public Entity {
    public:
        explicit Wall(unsigned id, Ressources &ressources);
    };
}


#endif //BOMBERMAN_WALL_HPP
