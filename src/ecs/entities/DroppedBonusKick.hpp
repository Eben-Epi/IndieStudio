/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** DroppedBonusKick.hpp
*/

#ifndef BOMBERMAN_DROPPEDBONUSKICK_HPP
#define BOMBERMAN_DROPPEDBONUSKICK_HPP

#include "../Entity.hpp"
#include "../Ressources.hpp"

namespace ECS
{
    class DroppedBonusKick : public Entity {
    public:
        explicit DroppedBonusKick(unsigned id, Ressources &ressources);
    };
}


#endif //BOMBERMAN_DROPPEDBONUSKICK_HPP
