/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Controller.hpp
*/

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "Input.hpp"

namespace Input
{
    class Controller : public Input 
    {
        public:
            Controller(Irrlicht::Irrlicht &, std::vector<unsigned> &&, unsigned);
            ~Controller();
            std::vector<Action> getActions();
            void changeKey(Action, unsigned); //keyCode -> controller Key Code

        private:
            Irrlicht::Irrlicht &_irrlicht;
            irr::SEvent *_event;
            std::vector<unsigned> _keys;
            unsigned _id;
    };
}

#endif