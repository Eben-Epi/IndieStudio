/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** ControllableComponent.cpp
*/

#include "ControllableComponent.hpp"

namespace ECS
{
    ControllableComponent::ControllableComponent(Input::Input &input, unsigned inputNbr) :
        Component("Controllable"),
        inputNbr(inputNbr),
        input(input)
    {
    }

    std::ostream& ControllableComponent::serialize(std::ostream &stream) const
    {
    	return stream << inputNbr;
    }
}