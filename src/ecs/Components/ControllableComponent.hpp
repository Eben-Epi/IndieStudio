/*
** EPITECH PROJECT, 2018
** ECS
** File description:
** ControllableComponent.hpp
*/

#ifndef CONTROLLERCOMPONENT_HPP
#define CONTROLLERCOMPONENT_HPP

#include "../Component.hpp"
#include "../../input/Input.hpp"

namespace ECS
{
    class ControllableComponent : public Component
    {
        public:
    	    Input::Input &input;
            ControllableComponent(Input::Input &);
    };
} // namespace ECS

#endif