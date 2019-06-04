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
            unsigned int health = 0;
            float speed = 0;
            unsigned int nbBomb = 0;
            bool kick = false;
            unsigned int hardness = 0;
            unsigned int range = 0;
            PowerUpComponent(std::map<std::string, NumericValue>);
    };
} // namespace ECS

#endif