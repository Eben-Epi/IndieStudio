/*
** EPITECH PROJECT, 2018
** ECS
** File description:
** PickerComponent.cpp
*/

#include <iostream>
#include "PickerComponent.hpp"

namespace ECS
{
    PickerComponent::PickerComponent() :
        Component("Picker")
    {

    }

    std::ostream& PickerComponent::serialize(std::ostream &stream) const
    {
    	return stream;
    }
}