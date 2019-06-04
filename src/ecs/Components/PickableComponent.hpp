/*
** EPITECH PROJECT, 2018
** ECS
** File description:
** PickableComponent.hpp
*/

#ifndef PICKABLECOMPONENT_HPP
#define PICKABLECOMPONENT_HPP

#include "../Component.hpp"
#include "../Entity.hpp"

namespace ECS
{
    class PickableComponent : public Component
    {
        public:
            Entity *pickedBy = nullptr;
            PickableComponent();
	    std::ostream &serialize(std::ostream &stream) const override;
    };
} // namespace ECS

#endif