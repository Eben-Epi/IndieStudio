/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** OwnerComponent.hpp
*/
#ifndef BOMBERMAN_OWNERCOMPONENT_HPP
#define BOMBERMAN_OWNERCOMPONENT_HPP

#include "../Component.hpp"
#include "../Ressources.hpp"

namespace ECS {
    class OwnerComponent : public Component {
    public:
        int ownerId;
        OwnerComponent();
        OwnerComponent(Ressources &ressources, std::istream &stream);
        std::ostream &serialize(std::ostream &stream) const override;
        bool hasOwner();
    };
}


#endif //BOMBERMAN_OWNERCOMPONENT_HPP
