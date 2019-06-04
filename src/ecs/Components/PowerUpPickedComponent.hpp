/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** PowerUpPickedComponent.hpp
*/

#ifndef BOMBERMAN_POWERUPPICKED_HPP
#define BOMBERMAN_POWERUPPICKED_HPP


#include "../Component.hpp"

namespace ECS
{
    class PowerUpPickedComponent : public Component
    {
    public:
        PowerUpPickedComponent();
        std::ostream &serialize(std::ostream &stream) const override;
    };
} // namespace ECS


#endif //BOMBERMAN_POWERUPPICKED_HPP
