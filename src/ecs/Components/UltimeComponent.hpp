/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** UltimeComponent.hpp
*/
#ifndef BOMBERMAN_ULTIMECOMPONENT_HPP
#define BOMBERMAN_ULTIMECOMPONENT_HPP


#include "../Component.hpp"
#include "../Ressources.hpp"

namespace ECS {
    class UltimeComponent : public Component {
    public:
        unsigned charge;

        UltimeComponent();
        UltimeComponent(const Ressources &ressources, std::istream &stream);
        std::ostream &serialize(std::ostream &stream) const override;

        bool ultimeIsReady();
    };
}


#endif //BOMBERMAN_ULTIMECOMPONENT_HPP
