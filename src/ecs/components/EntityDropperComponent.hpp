/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** EntityDropperComponent.hpp
*/

#ifndef ENTITYDROPPERCOMPONENT_HPP
#define ENTITYDROPPERCOMPONENT_HPP

#include <iostream>
#include "../Component.hpp"
#include "../Entity.hpp"

namespace ECS
{
    class EntityDropperComponent : public Component
    {
        public:
            std::string item;
            EntityDropperComponent();
            EntityDropperComponent(const unsigned id, Ressources &ressources, std::istream &stream);
            std::ostream &serialize(std::ostream &stream) const override;
    };
}

#endif