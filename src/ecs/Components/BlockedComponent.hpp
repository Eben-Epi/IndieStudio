/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** BlockedComponent.hpp
*/
#ifndef BOMBERMAN_BLOCKCOMPONENT_HPP
#define BOMBERMAN_BLOCKCOMPONENT_HPP

#include "../Component.hpp"

namespace ECS {
    class BlockedComponent : public Component {
    public:
        BlockedComponent();
	std::ostream &serialize(std::ostream &stream) const override;
    };
}

#endif //BOMBERMAN_BLOCKCOMPONENT_HPP
