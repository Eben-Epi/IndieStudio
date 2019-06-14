/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** DroppedBonusHealth.hpp
*/


#ifndef BOMBERMAN_DROPPEDBONUSHEALTH_HPP
#define BOMBERMAN_DROPPEDBONUSHEALTH_HPP


#include "../../Entity.hpp"
#include "../../Ressources.hpp"
#include "DroppedItem.hpp"

namespace ECS
{
    class DroppedBonusHealth : public DroppedItem {
    public:
        explicit DroppedBonusHealth(unsigned id, Ressources &ressources);
    };
}



#endif //BOMBERMAN_DROPPEDBONUSHEALTH_HPP
