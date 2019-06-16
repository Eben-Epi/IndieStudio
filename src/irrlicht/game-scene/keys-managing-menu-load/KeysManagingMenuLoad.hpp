/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** KeysManagingMenuLoad.hpp
*/

#ifndef KEY_MANAGING_MENU_LOAD_HPP
#define KEY_MANAGING_MENU_LOAD_HPP

#include <vector>
#include <memory>
#include "../GameScene.hpp"
#include "../hud/Button.hpp"
#include "../../../input/Input.hpp"

namespace Irrlicht
{
    class KeysManagingMenuLoad : public GameScene
    {
    public:
        KeysManagingMenuLoad(Screen &screen, const std::string &name, unsigned id, unsigned playersNb, unsigned iaNb, unsigned soundVolume);

        ~KeysManagingMenuLoad() = default;

        bool update() override;

    private:
        unsigned _playersNumber;
        unsigned _soundVolume;
        unsigned _iaNumber;
        std::vector<std::unique_ptr<Input::Input>> _inputs;
        irr::core::array<irr::SJoystickInfo> _joystickInfos;

    };
}

#endif