/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** ControllableComponent.cpp
*/

#include "ControllableComponent.hpp"
#include "../Exceptions.hpp"
#include "../../input/AIBrain.hpp"

namespace ECS
{
    ControllableComponent::ControllableComponent(Input::Input &input, unsigned inputNbr) :
        Component("Controllable"),
        inputNbr(inputNbr),
        input(input)
    {
    }

    std::ostream& ControllableComponent::serialize(std::ostream &stream) const
    {
        return stream << inputNbr << " " << input.isAI() << " EndOfComponent";
    }

    ControllableComponent::ControllableComponent(unsigned id, ECS::Ressources &ressources, std::istream &stream) :
        Component("Controllable"),
        inputNbr([&stream]() {
            unsigned nbr;

            stream >> nbr;
            return nbr;
        }()),
        inputCreated(nullptr),
        input(*[&stream, &ressources, this, &id]() {
            bool isAI;

            stream >> isAI;
            if (!isAI)
                return ressources.inputs.at(this->inputNbr);
            this->inputCreated.reset(new Input::AIBrain(id, ressources.core));
            return &*this->inputCreated;
        }())
    {
        std::string terminator;

        stream >> terminator;
        if (terminator != "EndOfComponent")
            throw InvalidSerializedStringException("The component terminator was not found");
    }
}