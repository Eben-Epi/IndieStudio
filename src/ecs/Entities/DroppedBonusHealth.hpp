/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** DroppedBonusHealth.hpp
*/


#ifndef BOMBERMAN_DROPPEDBONUSHEALTH_HPP
#define BOMBERMAN_DROPPEDBONUSHEALTH_HPP


#include "../Entity.hpp"
#include "../Ressources.hpp"

namespace ECS
{
    class DroppedBonusHealth : public Entity {
    public:
        explicit DroppedBonusHealth(unsigned id, const Ressources &ressources);
    };
}



#endif //BOMBERMAN_DROPPEDBONUSHEALTH_HPP
