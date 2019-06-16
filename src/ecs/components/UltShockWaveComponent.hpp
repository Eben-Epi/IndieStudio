/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** UltShockWaveComponent.hpp
*/
#ifndef BOMBERMAN_ULTSHOCKWAVECOMPONENT_HPP
#define BOMBERMAN_ULTSHOCKWAVECOMPONENT_HPP

#include "../Component.hpp"
#include "../Ressources.hpp"

namespace ECS {
    class UltShockWaveComponent : public Component {
    public:
        unsigned timer;
        unsigned waveCount;
        Vector2<int> origin;
        char direction;

        UltShockWaveComponent();
        UltShockWaveComponent(Ressources &ressources, std::istream &stream);
        std::ostream &serialize(std::ostream &stream) const override;
    };
}


#endif //BOMBERMAN_ULTSHOCKWAVECOMPONENT_HPP
