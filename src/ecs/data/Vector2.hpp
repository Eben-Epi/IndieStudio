/*
** EPITECH PROJECT, 2019
** ECS
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

        template <typename type>
        Vector2<T> &operator=(Vector2<type> &vec) {
            this->x = static_cast<type>(vec.x);
            this->y = static_cast<type>(vec.y);
            return *this;
        }
    };

    typedef Vector2<double> PointF;
    typedef Vector2<double> Point;
}; // namespace ECS


#endif