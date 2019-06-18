/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** MainMenu.cpp
*/

#include "MainMenu.hpp"
#include "../../../input/Keyboard.hpp"
#include "../../../config.hpp"

static std::vector<std::vector<irr::EKEY_CODE>> defaultKeyboardsKeys {
	{
		irr::KEY_KEY_Z,
		irr::KEY_KEY_D,
		irr::KEY_KEY_S,
		irr::KEY_KEY_Q,
		irr::KEY_KEY_E,
		irr::KEY_KEY_A
	},
	{
		irr::KEY_UP,
		irr::KEY_RIGHT,
		irr::KEY_DOWN,
		irr::KEY_LEFT,
		irr::KEY_RSHIFT,
		irr::KEY_RCONTROL
	},
	{
		irr::KEY_KEY_T,
		irr::KEY_KEY_H,
		irr::KEY_KEY_G,
		irr::KEY_KEY_F,
		irr::KEY_KEY_Y,
		irr::KEY_KEY_R
	},
	{
		irr::KEY_KEY_O,
		irr::KEY_KEY_M,
		irr::KEY_KEY_L,
		irr::KEY_KEY_K,
		irr::KEY_KEY_P,
		irr::KEY_KEY_I
	}
};

Irrlicht::MainMenu::MainMenu(Screen &screen, const std::string &name, unsigned id) :
	GameScene(screen, name, id)
{
	screen.soundSystem.setBackgroundMusic("title_screen_loop");
	screen.soundSystem.playSoundOverBackgroundMusic("title_screen_intro");
	this->_buttons.emplace_back(new Button({280, 150}, {20, 240, 110, 240 + 32}, NEW_GAME, this->_window.getGuiEnv(), "NEW GAME"));
	this->_buttons.emplace_back(new Button({280, 260}, {20, 240, 110, 240 + 32}, LOAD_GAME, this->_window.getGuiEnv(), "LOAD GAME"));
    this->_buttons.emplace_back(new Button({280, 550}, {20, 240, 110, 240 + 32}, EXIT, this->_window.getGuiEnv(), "EXIT"));

    this->_textBoxes.emplace_back(new TextBox({280, 25}, {20, 240, 110, 240 + 32}, 0, this->_window.getGuiEnv(), "BOMBERMAN", true, true, true));
    this->_textBoxes[0]->setBackgroundColor(irr::video::SColor(255, 255, 0, 0));
    this->_textBoxes[0]->setColorOfText(irr::video::SColor(255, 0, 0, 0));
}

bool Irrlicht::MainMenu::update()
{
    if (this->_clock >= FRAME_RATE * 40) {
        if (!this->_window.isValidGetterName("Demo"))
            this->_window.addGameSceneDemoMenu("Demo");
        changeCurrentGameScene("Demo");
        return (false);
    }
    this->_clock++;
    for (unsigned i = 0; i < this->_buttons.size(); i++) {
        if (this->isGuiButtonPressed(i)) {
	    this->_clock = 0;
            switch (i) {
                case NEW_GAME:
                    if (!this->_window.isValidGetterName("New Game Menu"))
                        this->_window.addGameSceneNewGameMenu("New Game Menu");
                    changeCurrentGameScene("New Game Menu");
                    return (true);
                case LOAD_GAME:

			for (int j = 0; j != 4; j++)
				this->_inputs.emplace_back(new Input::Keyboard(*this, defaultKeyboardsKeys[i]));
			if (!this->_window.isValidGetterName("Game"))
				this->_window.addGameSceneGame("Game", this->_inputs, "save.txt");
		    changeCurrentGameScene("Game");
		    return (true);
                case EXIT:
                    this->_window.getDevice()->closeDevice();
                    return (false);
                default:
                    break;
            }
        }
    }
    for (unsigned i = 0; i < this->_buttons.size(); i++)
        this->_buttons.at(i)->setVisible(true);
    for (unsigned i = 0; i < this->_textBoxes.size(); i++)
        this->_textBoxes.at(i)->setVisible(true);
    return (true);
}
