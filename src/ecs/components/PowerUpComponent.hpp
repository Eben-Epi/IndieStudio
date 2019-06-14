/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** PowerUpComponent.hpp
*/

#ifndef POWERUPCOMPONENT_HPP
#define POWERUPCOMPONENT_HPP

#include <map>
#include "../Component.hpp"
#include "../Ressources.hpp"
#include "../data/NumericValue.hpp"

namespace ECS
{
    class PowerUpComponent : public Component {
    public:
        bool kick;
        float speed;
        unsigned int health;
        unsigned int nbBomb;
        unsigned int hardness;
        unsigned int range;
        Sound::SoundSystem &soundSystem;
        PowerUpComponent(Sound::SoundSystem &sounds, std::map<std::string, NumericValue>);
        PowerUpComponent(unsigned id, Ressources &ressources, std::istream &stream);
        std::ostream &serialize(std::ostream &stream) const override;
    };
} // namespace ECS

#endif