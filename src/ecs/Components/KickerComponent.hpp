/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** KickerComponent.hpp
*/

#ifndef KICKERCOMPONENT_HPP
#define KICKERCOMPONENT_HPP

#include "../Component.hpp"

namespace ECS
{
    class KickerComponent : public Component {
        public:
            bool canKick = false;
            KickerComponent();
	    std::ostream &serialize(std::ostream &stream) const override;
    };
} // namespace ECS

#endif