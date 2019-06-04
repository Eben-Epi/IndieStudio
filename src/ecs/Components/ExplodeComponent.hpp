/*
** EPITECH PROJECT, 2018
** ECS
** File description:
** ExplodeComponent.hpp
*/

#ifndef EXPLODECOMPONENT_HPP
#define EXPLODECOMPONENT_HPP

#include "../Component.hpp"

namespace ECS
{
    class ExplodeComponent : public Component
    {
        public:
            unsigned int range;
            unsigned int strength;
            ExplodeComponent(unsigned int range, unsigned int strength);
	    std::ostream &serialize(std::ostream &stream) const override;
    };
} // namespace ECS

#endif