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
        input(input),
        stunLeft(0)
    {
    }

    std::ostream& ControllableComponent::serialize(std::ostream &stream) const
    {
    	return stream << this->inputNbr << " " << this->stunLeft << " EndOfComponent";
    }

    ControllableComponent::ControllableComponent(ECS::Ressources &ressources, std::istream &stream) :
        Component("Controllable"),
        inputNbr([&stream]() {
        	unsigned nbr;
        	stream >> nbr;
        	return nbr;
        }()),
        input(*ressources.inputs.at(this->inputNbr))
    {
	    std::string terminator;

	    stream >> this->stunLeft >> terminator;
	    if (terminator != "EndOfComponent")
		    throw InvalidSerializedStringException("The component terminator was not found");
    }

    bool ControllableComponent::stun(unsigned duration, bool force)
    {
        if (duration < this->stunLeft && !force)
            return false;
        this->stunLeft = duration;
        return true;
    }
}