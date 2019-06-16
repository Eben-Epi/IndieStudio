/*
** EPITECH PROJECT, 2018
** ECS
** File description:
** EphemeralComponent.hpp
*/

#ifndef EPHEMERALCOMPONENT_HPP
#define EPHEMERALCOMPONENT_HPP

#include "../Component.hpp"
#include "../Ressources.hpp"

namespace ECS
{
	class EphemeralComponent : public Component
	{
	public:
		unsigned int timeLeft;
		EphemeralComponent(unsigned int timeLeft);
		EphemeralComponent(unsigned id, Ressources &ressources, std::istream &stream);
		std::ostream &serialize(std::ostream &stream) const override;
	};
} // namespace ECS

#endif