/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Errors.hpp
*/

#ifndef ERRORS_HPP
#define ERRORS_HPP

#include <iostream>

namespace Input
{
    class InputException : public std::exception
    {
        std::string _message;

    public:
        InputException(std::string const &message) noexcept : _message(message) {};
        const char *what() const noexcept override { return this->_message.c_str(); };
    };

    class KeyboardException : public InputException
    {
    public:
        KeyboardException(std::string const &message) : InputException(message) {};
    };

    class ControllerException : public InputException
    {
    public:
        ControllerException(std::string const &message) : InputException(message) {};
    };
}

#endif