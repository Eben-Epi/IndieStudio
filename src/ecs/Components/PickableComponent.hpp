/*
** EPITECH PROJECT, 2018
** ECS
** File description:
** PickableComponent.hpp
*/

#ifndef PICKABLECOMPONENT_HPP
#define PICKABLECOMPONENT_HPP

#include "../Component.hpp"

namespace ECS
{
    class PickableComponent : public Component
    {
        public:
            PickableComponent();
	    std::ostream &serialize(std::ostream &stream) const override;
    };
} // namespace ECS

#endif