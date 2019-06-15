/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Sydney.cpp
*/

#include "Sydney.hpp"
#include "../components/UltInvincibilityComponent.hpp"

ECS::Sydney::Sydney(unsigned id, ECS::Ressources &ressources) :
	Player(id, ressources, "sydney", new UltInvincibilityComponent(), "sydney")
{
}