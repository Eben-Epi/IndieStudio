/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** KickableComponent.hpp
*/

#ifndef KICKABLE_HPP
#define KICKABLE_HPP

#include "../Component.hpp"
#include "../Ressources.hpp"

namespace ECS
{
    class KickableComponent : public Component
    {
        public:
            KickableComponent();
            KickableComponent(unsigned id, Ressources &ressources, std::istream &stream);
	    std::ostream &serialize(std::ostream &stream) const override;
    };
} // namespace ECS

#endif