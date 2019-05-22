/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SolidComponent.cpp
*/

#include "SolidComponent.hpp"

namespace ECS
{
    Solid::Solid(unsigned int hardness)
    : Component("Solid")
    {
        this->_hardness = hardness;
    }
}