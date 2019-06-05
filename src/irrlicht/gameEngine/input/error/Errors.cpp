/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Errors.cpp
*/

#include "Errors.hpp"

Input::Errors::Errors(std::string const &message) noexcept
:   _message(message)
{
}

const char *Input::Errors::Errors::what() const noexcept
{
    return (_message.c_str());
}

Input::KeyboardErrors::KeyboardErrors()
: Errors("there is an error with the Keyboard")
{
}

Input::ControllerErrors::ControllerErrors()
: Errors("there is an error with the Controller")
{
}