/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** MovableComponent.hpp
*/

#ifndef MOVABLECOMPONENT_HPP
#define MOVABLECOMPONENT_HPP

#include "../Component.hpp"
#include "../data/Directions.hpp"

namespace ECS
{
    class MovableComponent : public Component
    {
        public:
            unsigned char dir;
            float speed;
            float maxSpeed;
            MovableComponent(float maxSpeed);
    };
} // namespace ECS

#endif