/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** DroppedBonusRange.hpp
*/

#ifndef BOMBERMAN_DROPPEDBONUSRANGE_HPP
#define BOMBERMAN_DROPPEDBONUSRANGE_HPP


#include "../../Entity.hpp"
#include "../../Ressources.hpp"
#include "DroppedItem.hpp"

namespace ECS
{
    class DroppedBonusRange : public DroppedItem {
    public:
        explicit DroppedBonusRange(unsigned id, Ressources &ressources);
    };
}

#endif //BOMBERMAN_DROPPEDBONUSRANGE_HPP
