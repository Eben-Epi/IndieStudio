/*
** EPITECH PROJECT, 2018
** ECS
** File description:
** ExplodeComponent.hpp
*/

#ifndef EXPLODECOMPONENT_HPP
#define EXPLODECOMPONENT_HPP

#include "../Component.hpp"

namespace ECS
{
    class ExplodeComponent : public Component
    {
        public:
            unsigned int range;
            ExplodeComponent(unsigned int range);
    };
} // namespace ECS

#endif