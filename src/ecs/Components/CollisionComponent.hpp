/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** SolidComponent.hpp
*/

#ifndef SOLIDCOMPONENT_HPP
#define SOLIDCOMPONENT_HPP

#include "../Component.hpp"
#include "../Entity.hpp"
#include <vector>

namespace ECS
{
    class CollisionComponent : public Component
    {
        public:
            unsigned int hardness;
            unsigned int passthough;
            std::vector<Entity*> entitiesCollided = {};
            CollisionComponent(unsigned int hardness, unsigned int pass);
    };
} // namespace ECS

#endif