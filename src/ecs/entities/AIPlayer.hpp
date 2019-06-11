/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** AIPlayer.hpp
*/

#ifndef BOMBERMAN_AIPLAYER_HPP
#define BOMBERMAN_AIPLAYER_HPP


#include "../Entity.hpp"
#include "../Ressources.hpp"

namespace ECS
{
    class AIPlayer : public Entity {
    public:
        explicit AIPlayer(unsigned id, Ressources &ressources);
    };
}

#endif //BOMBERMAN_AIPLAYER_HPP
