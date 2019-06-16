/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** UltBombRainComponent.hpp
*/
#ifndef BOMBERMAN_ULTBOMBRAINCOMPONENT_HPP
#define BOMBERMAN_ULTBOMBRAINCOMPONENT_HPP


#include "../Component.hpp"
#include "../Ressources.hpp"

namespace ECS {
    class UltBombRainComponent : public Component {
    public:
        unsigned timer;
        unsigned bombCount;

        UltBombRainComponent();
        UltBombRainComponent(Ressources &ressources, std::istream &stream);
        std::ostream &serialize(std::ostream &stream) const override;
    };
}


#endif //BOMBERMAN_ULTBOMBRAINCOMPONENT_HPP
