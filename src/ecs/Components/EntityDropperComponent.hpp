/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** ItemDropperComponent.hpp
*/

#ifndef ITEMCONTAINERCOMPONENT_HPP
#define ITEMCONTAINERCOMPONENT_HPP

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