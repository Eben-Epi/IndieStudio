/*
** EPITECH PROJECT, 2018
** ECS
** File description:
** PicherComponent.hpp
*/

#ifndef PICKERCOMPONENT_HPP
#define PICKERCOMPONENT_HPP

#include "../Component.hpp"
#include "../Ressources.hpp"

namespace ECS
{
    class PickerComponent : public Component
    {
        public:
            PickerComponent();
            PickerComponent(unsigned id, Ressources &ressources, std::istream &stream);
	    std::ostream &serialize(std::ostream &stream) const override;
    };
} // namespace ECS

#endif