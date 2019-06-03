/*
** EPITECH PROJECT, 2018
** ECS
** File description:
** PickableComponent.cpp
*/

#include <iostream>
#include "PickableComponent.hpp"

namespace ECS
{
    PickableComponent::PickableComponent() :
        Component("Pickable")
    {

    }

    std::ostream& PickableComponent::serialize(std::ostream &stream) const
    {
    	return stream;
    }
}