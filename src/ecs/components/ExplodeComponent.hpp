/*
** EPITECH PROJECT, 2018
** ECS
** File description:
** ExplodeComponent.hpp
*/

#ifndef EXPLODECOMPONENT_HPP
#define EXPLODECOMPONENT_HPP

#include "../Component.hpp"
#include "../Ressources.hpp"

namespace ECS
{
    class ExplodeComponent : public Component
    {
        public:
            Sound::SoundSystem &soundSystem;
            unsigned int range;
            unsigned int strength;
            ExplodeComponent(Sound::SoundSystem &soundSystem, unsigned int range, unsigned int strength);
            ExplodeComponent(unsigned id, Ressources &ressources, std::istream &stream);
	    std::ostream &serialize(std::ostream &stream) const override;
    };
} // namespace ECS

#endif