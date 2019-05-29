/*
** EPITECH PROJECT, 2019
** ECS
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
            ECS::Directions dir;
            float speed;
            float maxSpeed;
            MovableComponent(float maxSpeed);
    };
} // namespace ECS

#endif