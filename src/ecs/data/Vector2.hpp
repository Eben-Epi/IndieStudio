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

        Vector2<T> &operator+(T value) {
            this->x += value;
            this->y += value;
            return *this;
        }

        Vector2<T> &operator*(T value) {
            this->x *= value;
            this->y *= value;
            return *this;
        }

        template <typename type>
        operator Vector2<type>() {
            return {
               static_cast<type>(this->x),
	       static_cast<type>(this->y)
            };
        }
    };

    typedef Vector2<double> Point;
} // namespace ECS


#endif