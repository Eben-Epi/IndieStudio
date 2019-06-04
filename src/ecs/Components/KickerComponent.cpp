/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** KickerComponent.cpp
*/

#include <iostream>
#include "KickerComponent.hpp"

namespace ECS
{
    KickerComponent::KickerComponent()
    : Component("Kicker")
    {
    }

    std::ostream& KickerComponent::serialize(std::ostream &stream) const
    {
    	return stream << "EndOfComponent";
    }
}