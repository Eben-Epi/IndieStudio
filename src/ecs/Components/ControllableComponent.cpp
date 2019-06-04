/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** ControllableComponent.cpp
*/

#include "ControllableComponent.hpp"
#include "../Exceptions.hpp"

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
    	return stream << inputNbr << " EndOfComponent";
    }

    ControllableComponent::ControllableComponent(const ECS::Ressources &ressources, std::istream &stream) :
        Component("Controllable"),
        inputNbr([&stream]() {
        	unsigned nbr;
        	stream >> nbr;
        	return nbr;
        }()),
        input(*ressources.inputs.at(this->inputNbr))
    {
	    std::string terminator;

	    stream >> terminator;
	    if (terminator != "EndOfComponent")
		    throw InvalidSerializedStringException("The component terminator was not found");
    }
}