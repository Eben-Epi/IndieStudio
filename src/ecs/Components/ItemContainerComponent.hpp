/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** ItemContainerComponent.hpp
*/

#ifndef ITEMCONTAINERCOMPONENT_HPP
#define ITEMCONTAINERCOMPONENT_HPP

#include "../Component.hpp"
#include "../Entity.hpp"

namespace ECS
{
    class ItemContainerComponent : public Component
    {
        public:
            std::vector<Entity> items;
            ItemContainerComponent();
    };
}

#endif