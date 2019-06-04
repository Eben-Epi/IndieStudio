/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** KickableComponent.cpp
*/

#include <iostream>
#include "KickableComponent.hpp"

namespace ECS
{
    KickableComponent::KickableComponent()
    : Component("KickableComponent")
    {
    }

    std::ostream& KickableComponent::serialize(std::ostream &stream) const
    {
    	return stream << "EndOfComponent";
    }
}