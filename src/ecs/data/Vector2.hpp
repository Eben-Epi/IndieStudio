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

        Vector2<T> operator+(T value) {
	    Vector2<T> val = *this;

            val.x += value;
	    val.y += value;
            return val;
        }

        Vector2<T> operator*(T value) {
	    Vector2<T> val = *this;

	    val.x *= value;
	    val.y *= value;
	    return val;
        }

        template <typename type>
        operator Vector2<type>() {
            return {
               static_cast<type>(this->x),
               static_cast<type>(this->y)
            };
        }
    };

    template <typename T>
    struct Vector4 {
        T a;
        T b;
        T c;
        T d;

        template <typename type>
        Vector4<T> &operator=(Vector4<type> &vec) {
            this->a = static_cast<type>(vec.a);
            this->b = static_cast<type>(vec.b);
            this->c = static_cast<type>(vec.c);
            this->d = static_cast<type>(vec.d);
            return *this;
        }
    };

    typedef Vector2<double> PointF;
    typedef Vector2<double> Point;
} // namespace ECS


#endif