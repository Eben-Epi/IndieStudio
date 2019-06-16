/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** PowerUpPickedComponent.hpp
*/

#ifndef BOMBERMAN_POWERUPPICKED_HPP
#define BOMBERMAN_POWERUPPICKED_HPP


#include "../Component.hpp"
#include "../Ressources.hpp"


namespace ECS
{
    class PowerUpPickedComponent : public Component
    {
    public:
        PowerUpPickedComponent();
        PowerUpPickedComponent(const unsigned id, Ressources &ressources, std::istream &stream);
        std::ostream &serialize(std::ostream &stream) const override;
    };
} // namespace ECS


#endif //BOMBERMAN_POWERUPPICKED_HPP
