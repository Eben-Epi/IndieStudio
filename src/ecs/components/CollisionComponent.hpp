/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** SolidComponent.hpp
*/

#ifndef SOLIDCOMPONENT_HPP
#define SOLIDCOMPONENT_HPP

#include "../Component.hpp"
#include "../Entity.hpp"
#include "../Ressources.hpp"
#include <vector>

namespace ECS
{
    class CollisionComponent : public Component
    {
        public:
            unsigned int passThrough;
            std::vector<Entity*> entitiesCollided = {};
            explicit CollisionComponent(unsigned int pass);
            CollisionComponent(unsigned id, Ressources &ressources, std::istream &stream);
	    std::ostream &serialize(std::ostream &stream) const override;
    };
} // namespace ECS

#endif