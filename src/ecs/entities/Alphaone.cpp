/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Gunguy.cpp
*/

#include "Alphaone.hpp"
#include "../components/UltBombRainComponent.hpp"

ECS::Alphaone::Alphaone(unsigned id, ECS::Ressources &ressources) :
	Player(id, ressources, "Alphaone", new UltBombRainComponent(), "gunguy")
{
}
