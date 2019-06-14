/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** OOBKillComponent.hpp
*/
#ifndef BOMBERMAN_OOBKILLCOMPONENT_HPP
#define BOMBERMAN_OOBKILLCOMPONENT_HPP


#include "../Component.hpp"
#include "../data/Vector2.hpp"
#include "../Ressources.hpp"

namespace ECS {
    class OOBKillComponent : public Component {
    public:
        Point p1;
        Point p2;
        OOBKillComponent(Point p1, Point p2, bool size_mode=false);
        OOBKillComponent(unsigned id, Ressources &ressources, std::istream &stream);
        std::ostream &serialize(std::ostream &stream) const override;
    };
}


#endif //BOMBERMAN_OOBKILLCOMPONENT_HPP
