/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Faerie.cpp
*/

#include "Faerie.hpp"
#include "../components/UltStrikeComponent.hpp"

ECS::Faerie::Faerie(unsigned id, ECS::Ressources &ressources) :
	Player(id, ressources, "faerie", new UltStrikeComponent(), "lonie")
{
}