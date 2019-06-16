/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** MovableComponent.hpp
*/

#ifndef MOVABLECOMPONENT_HPP
#define MOVABLECOMPONENT_HPP

#include "../Component.hpp"
#include "../data/Directions.hpp"
#include "../Ressources.hpp"

namespace ECS
{
    class MovableComponent : public Component
    {
        public:
            unsigned char dir;
            float speed;
            float maxSpeed;
            MovableComponent(float maxSpeed);
            MovableComponent(unsigned id, Ressources &ressources, std::istream &stream);
	    std::ostream &serialize(std::ostream &stream) const override;
    };
} // namespace ECS

#endif