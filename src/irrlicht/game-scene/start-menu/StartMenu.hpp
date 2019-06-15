/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** StartMenu.hpp
*/

#ifndef BOMBERMAN_STARTMENU_HPP
#define BOMBERMAN_STARTMENU_HPP

#include <vector>
#include <memory>
#include "../GameScene.hpp"
#include "../main-menu/Button.hpp"
#include "../../textbox/TextBox.hpp"

namespace Irrlicht
{
	enum StartButtonName
	{
		NEXT_FROM_NEW_GAME = 0,
		BACK_FROM_NEW_GAME,
		SAVE_SLOT_LESS,
		SAVE_SLOT_MORE,
		NUMBER_OF_PLAYERS_LESS,
		NUMBER_OF_PLAYERS_MORE,
		NUMBER_OF_AI_LESS,
		NUMBER_OF_AI_MORE,
		SOUND_LESS,
		SOUND_MORE,
		SOUND_MUTE

		// INPUT_P1,
		// INPUT_P2,
		// INPUT_P3,
		// INPUT_P4,
		// P1_UP,
		// P1_DOWN,
		// P1_LEFT,
		// P1_RIGHT,
		// P1_DROP,
		// P1_ULT,
		// P2_UP,
		// P2_DOWN,
		// P2_LEFT,
		// P2_RIGHT,
		// P2_DROP,
		// P2_ULT,
		// P3_UP,
		// P3_DOWN,
		// P3_LEFT,
		// P3_RIGHT,
		// P3_DROP,
		// P3_ULT,
		// P4_UP,
		// P4_DOWN,
		// P4_LEFT,
		// P4_RIGHT,
		// P4_DROP,
		// P4_ULT,
	};

	class StartMenu : public GameScene
	{
	public:
		StartMenu(Screen &screen, const std::string &name, unsigned id);
		~StartMenu() = default;
		void changeCurrentGameScene(std::string sceneName);
		bool update() override;

	private:
		//PROPERTIES
		std::vector<std::unique_ptr<Button>> _buttons;
		std::vector<std::unique_ptr<TextBox>> _textBoxes;
	};
}

#endif //BOMBERMAN_MAINMENU_HPP
