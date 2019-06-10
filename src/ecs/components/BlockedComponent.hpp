/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** BlockedComponent.hpp
*/
#ifndef BOMBERMAN_BLOCKCOMPONENT_HPP
#define BOMBERMAN_BLOCKCOMPONENT_HPP

#include "../Component.hpp"
#include "../Ressources.hpp"
#include "../Entity.hpp"

namespace ECS {
    class BlockedComponent : public Component {
    public:
        std::vector<Entity*> _whitelistId;

        BlockedComponent();
        BlockedComponent(Ressources &ressources, std::istream &stream);
        std::ostream &serialize(std::ostream &stream) const override;
    };
}

#endif //BOMBERMAN_BLOCKCOMPONENT_HPP
