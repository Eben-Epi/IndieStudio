/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** UltStrikeComponent.hpp
*/
#ifndef BOMBERMAN_ULTSTRIKECOMPONENT_HPP
#define BOMBERMAN_ULTSTRIKECOMPONENT_HPP


#include "../Component.hpp"
#include "../Ressources.hpp"

namespace ECS {
    class UltStrikeComponent : public Component {
    public:
        unsigned timer;

        UltStrikeComponent();
        UltStrikeComponent(Ressources &ressources, std::istream &stream);
        std::ostream &serialize(std::ostream &stream) const override;
    };
};


#endif //BOMBERMAN_ULTSTRIKECOMPONENT_HPP
