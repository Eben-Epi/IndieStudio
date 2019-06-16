/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Keybord.hpp
*/

#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include "Input.hpp"
#include "../irrlicht/game-scene/GameScene.hpp"

namespace Input
{
    class Keyboard : public Input {
    public:
        Keyboard(Irrlicht::GameScene &, std::vector<irr::EKEY_CODE> &);

        ~Keyboard();

        void changeKey(Action, irr::EKEY_CODE);
        std::vector<Action> getActions() override;
        void resetControl() override;
        bool isAI() override;
        std::string getEnumControlString(Action code);

    private:
        Irrlicht::GameScene &_scene;
        std::vector<irr::EKEY_CODE> _keys;
        std::vector<irr::EKEY_CODE> _default;
        Action _act = Action::NO_ACTION;
    };
}


#endif