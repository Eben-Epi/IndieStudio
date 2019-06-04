/*
** EPITECH PROJECT, 2018
** ECS
** File description:
** PickableComponent.hpp
*/

#ifndef PICKABLECOMPONENT_HPP
#define PICKABLECOMPONENT_HPP

#include "../Component.hpp"
#include "../Ressources.hpp"

namespace ECS
{
    class PickableComponent : public Component
    {
        public:
            PickableComponent();
            PickableComponent(const Ressources &ressources, std::istream &stream);
	    std::ostream &serialize(std::ostream &stream) const override;
    };
} // namespace ECS

#endif