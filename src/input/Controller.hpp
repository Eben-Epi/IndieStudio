/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Controller.hpp
*/

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "Input.hpp"

namespace input
{
    class Controller : public Input
    {
        public:
            Controller();
            ~Controller();
            std::vector<input::Action> getNextAction();
            void changeKey(input::Action, irr::EKEY_CODE); //keyCode -> controller Key Code

        private:
    };
}

#endif