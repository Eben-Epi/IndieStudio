/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** DroppedBonusHardness.hpp
*/

#ifndef BOMBERMAN_DROPPEDBONUSHARDNESS_HPP
#define BOMBERMAN_DROPPEDBONUSHARDNESS_HPP

#include "../Entity.hpp"
#include "../Ressources.hpp"

namespace ECS
{
    class DroppedBonusHardness : public Entity {
    public:
        explicit DroppedBonusHardness(unsigned id, const Ressources &ressources);
    };
}

#endif //BOMBERMAN_DROPPEDBONUSHARDNESS_HPP
