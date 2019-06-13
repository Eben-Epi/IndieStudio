/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** DroppedItem.hpp
*/


#ifndef BOMBERMAN_DROPPEDITEM_HPP
#define BOMBERMAN_DROPPEDITEM_HPP

#include "../../Entity.hpp"
#include "../../Ressources.hpp"
#include "../../data/NumericValue.hpp"

namespace ECS
{
    class DroppedItem : public Entity {
    public:
        explicit DroppedItem(unsigned id, Ressources &ressources, std::string &&texture, std::map<std::string, NumericValue> &&map);
    };
}


#endif //BOMBERMAN_DROPPEDITEM_HPP
