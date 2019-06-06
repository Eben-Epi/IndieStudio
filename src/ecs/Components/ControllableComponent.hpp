/*
** EPITECH PROJECT, 2018
** ECS
** File description:
** ControllableComponent.hpp
*/

#ifndef CONTROLLERCOMPONENT_HPP
#define CONTROLLERCOMPONENT_HPP

#include "../Component.hpp"
#include "../../irrlicht/GameScene/Input/Input.hpp"
#include "../Ressources.hpp"

namespace ECS
{
    class ControllableComponent : public Component
    {
        public:
    	    unsigned inputNbr;
    	    Input::Input &input;
            ControllableComponent(Input::Input &, unsigned);
            ControllableComponent(const Ressources &ressources, std::istream &stream);
	    std::ostream &serialize(std::ostream &stream) const override;
    };
} // namespace ECS

#endif