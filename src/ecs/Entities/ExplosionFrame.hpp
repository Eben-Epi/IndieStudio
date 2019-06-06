/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** ExplosionFrame.hpp
*/

#ifndef BOMBERMAN_EXPLOSIONFRAME_HPP
#define BOMBERMAN_EXPLOSIONFRAME_HPP

#include "../Entity.hpp"
#include "../Ressources.hpp"

namespace ECS {
    class ExplosionFrame : public Entity {
    public :
        explicit ExplosionFrame(unsigned id, Ressources &ressources);
    };
}


#endif //BOMBERMAN_EXPLOSIONFRAME_HPP
