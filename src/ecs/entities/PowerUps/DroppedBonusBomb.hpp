/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** DroppedBonusBomb.hpp
*/

#ifndef BOMBERMAN_DROPPEDBONUSBOMB_HPP
#define BOMBERMAN_DROPPEDBONUSBOMB_HPP


#include "../../Entity.hpp"
#include "../../Ressources.hpp"
#include "DroppedItem.hpp"

namespace ECS
{
    class DroppedBonusBomb : public DroppedItem {
    public:
        explicit DroppedBonusBomb(unsigned id, Ressources &ressources);
    };
}


#endif //BOMBERMAN_DROPPEDBONUSBOMB_HPP
