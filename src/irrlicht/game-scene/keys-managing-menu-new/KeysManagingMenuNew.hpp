/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** KeysManagingMenuNew.hpp
*/

#ifndef KEY_MANAGING_MENU_NEW_HPP
#define KEY_MANAGING_MENU_NEW_HPP

#include <vector>
#include <memory>
#include "../GameScene.hpp"
#include "../hud/Button.hpp"
#include "../../../input/Input.hpp"

namespace Irrlicht
{
	class KeysManagingMenuNew : public GameScene
	{
	public:
		KeysManagingMenuNew(Screen &screen, const std::string &name, unsigned id, unsigned playersNb, unsigned iaNb, unsigned soundVolume);

		~KeysManagingMenuNew() = default;
		unsigned joysticksAvailable();
		void assignNextJoystick(unsigned player);

		bool update() override;

	private:
        unsigned _playersNumber;
        unsigned _soundVolume;
        unsigned _iaNumber;
        std::vector<std::unique_ptr<Input::Input>> _inputs;
        irr::core::array<irr::SJoystickInfo> _joystickInfos;
        std::vector<unsigned> _isPlayerJoystick;
    };
}

#endif