/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** DroppedBonusSpeed.hpp
*/

#ifndef BOMBERMAN_DROPPEDBONUSSPEED_HPP
#define BOMBERMAN_DROPPEDBONUSSPEED_HPP

#include "../Entity.hpp"
#include "../Ressources.hpp"

namespace ECS
{
    class DroppedBonusSpeed : public Entity {
    public:
        explicit DroppedBonusSpeed(unsigned id, Ressources &ressources);
    };
}


#endif //BOMBERMAN_DROPPEDBONUSSPEED_HPP
