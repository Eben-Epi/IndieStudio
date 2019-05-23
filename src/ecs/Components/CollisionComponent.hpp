/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** SolidComponent.hpp
*/

#ifndef SOLIDCOMPONENT_HPP
#define SOLIDCOMPONENT_HPP

#include "../Component.hpp"

namespace ECS
{
    class CollisionComponent : public Component
    {
        public:
            unsigned int hardness;
            CollisionComponent(unsigned int hardness);
    };
} // namespace ECS

#endif