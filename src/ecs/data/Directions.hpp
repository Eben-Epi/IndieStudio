/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** Directions.hpp
*/

#ifndef DIRECTIONS_HPP
#define DIRECTIONS_HPP

namespace ECS
{
    enum Directions
    {
        UP = 0b1,
        RIGHT = 0b10,
        DOWN = 0b100,
        LEFT = 0b1000
    };
}; // namespace ECS

#endif