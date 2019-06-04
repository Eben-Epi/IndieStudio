/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** EntityDropperComponent.hpp
*/

#ifndef ENTITYDROPPERCOMPONENT_HPP
#define ENTITYDROPPERCOMPONENT_HPP

#include "../Component.hpp"
#include "../Entity.hpp"

namespace ECS
{
    class EntityDropperComponent : public Component
    {
        public:
            std::vector<std::string> items;
            EntityDropperComponent();
    };
}

#endif