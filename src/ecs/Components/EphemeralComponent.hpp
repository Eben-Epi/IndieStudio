/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** EphemeralComponent.hpp
*/

#ifndef EPHEMERALCOMPONENT_HPP
#define EPHEMERALCOMPONENT_HPP

#include "../Component.hpp"

namespace ECS
{
	class EphemeralComponent : public Component
	{
		public:
			unsigned int timeLeft;
			EphemeralComponent(unsigned int timeLeft);
	};
} // namespace ECS

#endif