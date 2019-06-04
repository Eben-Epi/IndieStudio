/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** KickableComponent.hpp
*/

#ifndef KICKABLE_HPP
#define KICKABLE_HPP

#include "../Component.hpp"

namespace ECS
{
    class KickableComponent : public Component
    {
        public:
            KickableComponent();
	    std::ostream &serialize(std::ostream &stream) const override;
    };
} // namespace ECS

#endif