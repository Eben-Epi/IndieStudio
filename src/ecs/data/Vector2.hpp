/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** Vector2.hpp
*/

#ifndef VECTOR2_HPP
#define VECTOR2_HPP

namespace ECS
{
    template <typename T>
    struct Vector2 {
        T x;
        T y;
    };

    typedef Vector2<int> Point;
}; // namespace ECS

#endif