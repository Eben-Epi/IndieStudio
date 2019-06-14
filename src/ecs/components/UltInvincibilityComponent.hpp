/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** UltInvincibilityComponent.hpp
*/
#ifndef BOMBERMAN_ULTINVINCIBILITYCOMPONENT_HPP
#define BOMBERMAN_ULTINVINCIBILITYCOMPONENT_HPP


#include "../Component.hpp"
#include "../Ressources.hpp"

namespace ECS {
    class UltInvincibilityComponent : public Component {
    public:
        unsigned oldPassThrough;
        bool isOnUse;
        unsigned timeLeft;

        UltInvincibilityComponent();
        UltInvincibilityComponent(unsigned id, Ressources &ressources, std::istream &stream);
        std::ostream &serialize(std::ostream &stream) const override;
    };
}


#endif //BOMBERMAN_ULTINVINCIBILITYCOMPONENT_HPP
