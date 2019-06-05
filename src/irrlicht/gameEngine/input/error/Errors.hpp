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
    class Errors : public std::exception
    {
      std::string _message;

    public:
      Errors(std::string const &message) noexcept;
      const char *what() const noexcept override;
    };

    class KeyboardErrors : public Errors
    {
      public:
        KeyboardErrors();
    };
    class ControllerErrors : public Errors
    {
      public:
        ControllerErrors();
    };
}

#endif