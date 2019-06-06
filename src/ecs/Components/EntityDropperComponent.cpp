/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** EntityDropperComponent.cpp
*/

#include "EntityDropperComponent.hpp"
#include "../Exceptions.hpp"

namespace ECS
{
    EntityDropperComponent::EntityDropperComponent() :
    	Component("EntityDropper")
    {
    }

    EntityDropperComponent::EntityDropperComponent(const Ressources &ressources, std::istream &stream) :
        Component("EntityDropper")
    {
        std::string out;

        for (stream >> out; out != "EndOfComponent"; stream >> out) {
            if (stream.eof())
                throw InvalidSerializedStringException("Unexpected End Of File");
            this->items.push_back(out);
        }
    }

    std::ostream& EntityDropperComponent::serialize(std::ostream &stream) const
    {
        for (const std::string &bonus : this->items)
        {
            stream << bonus + " ";
        }
        return stream << "EndOfComponent";
    }
}
