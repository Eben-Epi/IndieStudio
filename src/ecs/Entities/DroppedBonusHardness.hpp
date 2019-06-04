/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** DroppedBonusHardness.hpp
*/

#ifndef BOMBERMAN_DROPPEDBONUSRANGE_HPP
#define BOMBERMAN_DROPPEDBONUSRANGE_HPP

#include "../Entity.hpp"
#include "../Ressources.hpp"

namespace ECS
{
    class DroppedBonusHardness : public Entity {
    public:
        explicit DroppedBonusHardness(unsigned id, const Ressources &ressources);
    };
}

#endif //BOMBERMAN_DROPPEDBONUSRANGE_HPP
