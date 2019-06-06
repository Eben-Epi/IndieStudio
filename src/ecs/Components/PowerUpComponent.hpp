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

namespace ECS
{
    class NumericValue {
    private:
        double value;

    public:
        NumericValue() : value(0) {};

        template<typename type>
        NumericValue(type val) : value(val) {};

        template<typename type>
        operator type()
        {
            return this->value;
        }
    };

    class PowerUpComponent : public Component
    {
    public:
        bool kick;
        float speed;
        unsigned int health;
        unsigned int nbBomb;
        unsigned int hardness;
        unsigned int range;
        PowerUpComponent(std::map<std::string, NumericValue>);
        PowerUpComponent(Ressources &ressources, std::istream &stream);
        std::ostream &serialize(std::ostream &stream) const override;
    };
} // namespace ECS

#endif