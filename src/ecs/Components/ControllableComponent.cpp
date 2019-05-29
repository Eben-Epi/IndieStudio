/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** ControllableComponent.cpp
*/

#include "ControllableComponent.hpp"

namespace ECS
{
    ControllableComponent::ControllableComponent(Input::Input &input) :
        Component("Controllable"),
        input(input)
    {
    }
}