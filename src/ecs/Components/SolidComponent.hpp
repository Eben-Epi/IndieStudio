/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SolidComponent.hpp
*/

#ifndef SOLIDCOMPONENT_HPP
#define SOLIDCOMPONENT_HPP

#include "Component.hpp"

namespace ECS
{
    class Solid : public Component
    {
        public:
            unsigned int _hardness;
            Solid(unsigned int hardness);
    };
} // namespace ECS

#endif