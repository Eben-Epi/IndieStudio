/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** ItemContainerComponent.hpp
*/

#ifndef ITEMCONTAINERCOMPONENT_HPP
#define ITEMCONTAINERCOMPONENT_HPP

#include "Component.hpp"
#include "ItemEntity.hpp"

namespace ECS
{
    class ItemContainer: public Component
    {
        public:
            std::vector<Item> _items;
            ItemContainer();
    }
}

#endif