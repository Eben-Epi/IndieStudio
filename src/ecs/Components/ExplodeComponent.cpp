/*
** EPITECH PROJECT, 2018
** ECS
** File description:
** ExplodeComponent.cpp
*/

#include "ExplodeComponent.hpp"

namespace ECS
{
    ExplodeComponent::ExplodeComponent(unsigned int range, unsigned int strength) :
        Component("Controller"),
        range(range),
        strength(strength),
    {
    }
}