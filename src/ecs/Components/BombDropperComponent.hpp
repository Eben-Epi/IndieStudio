/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** BombDropperComponent.hpp
*/

#ifndef BOMBDROPpERCOMPONENT_HPP
#define BOMBDROPpERCOMPONENT_HPP

#include <vector>
#include "Component.hpp"
#include "BombEntity.hpp"

namespace ECS
{
    class BombDropper : public Component
    {
        public:
            std::vector<Bomb> _bombs;
            unsigned int _max;
            float _timeToExplode;
            unsigned int _range;
            BombDropper();
    };
} // namespace ECS

#endif