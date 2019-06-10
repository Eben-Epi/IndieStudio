/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** ControlledByAIComponent.hpp
*/

#ifndef BOMBERMAN_CONTROLLEDBYAICOMPONENT_HPP
#define BOMBERMAN_CONTROLLEDBYAICOMPONENT_HPP


#include "../Component.hpp"
#include "../../input/Input.hpp"
#include "../Ressources.hpp"

namespace ECS
{
    class ControlledByAIComponent : public Component
    {
    public:
        unsigned smartness;
        bool isControlled;
        ControlledByAIComponent(unsigned, bool isControlled = false);
        ControlledByAIComponent(Ressources &ressources, std::istream &stream);
        std::ostream &serialize(std::ostream &stream) const override;
    };
} // namespace ECS

#endif //BOMBERMAN_CONTROLLEDBYAICOMPONENT_HPP
