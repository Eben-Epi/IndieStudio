/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** DroppedBonusRange.hpp
*/

#ifndef BOMBERMAN_DROPPEDBONUSRANGE_HPP
#define BOMBERMAN_DROPPEDBONUSRANGE_HPP


#include "../Entity.hpp"
#include "../Ressources.hpp"

namespace ECS
{
    class DroppedBonusRange : public Entity {
    public:
        explicit DroppedBonusRange(unsigned id, const Ressources &ressources);
    };
}

#endif //BOMBERMAN_DROPPEDBONUSRANGE_HPP
