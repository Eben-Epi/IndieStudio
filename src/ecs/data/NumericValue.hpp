/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** NumericValue.hpp
*/
#ifndef BOMBERMAN_NUMERICVALUE_HPP
#define BOMBERMAN_NUMERICVALUE_HPP

namespace ECS {
    class NumericValue {
    private:
        double value;

    public:
        NumericValue() : value(0) {};

        template<typename type>
        NumericValue(type val) : value(val) {};

        template<typename type>
        operator type() {
            return this->value;
        }
    };
}

#endif //BOMBERMAN_NUMERICVALUE_HPP
