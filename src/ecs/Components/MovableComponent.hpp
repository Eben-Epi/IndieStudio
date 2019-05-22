/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** MovableComponent.hpp
*/

#ifndef MOVABLECOMPONENT_HPP
#define MOVABLECOMPONENT_HPP

#include "Component.hpp"

namespace ECS
{
    class Movable : public Component
    {
        public:
            float _speed;
            Movable(float speed);
    };
} // namespace ECS

#endif