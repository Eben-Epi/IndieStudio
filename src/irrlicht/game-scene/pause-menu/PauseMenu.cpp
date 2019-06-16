/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** PauseMenu.cpp
*/

#include "PauseMenu.hpp"

Irrlicht::PauseMenu::PauseMenu(Screen &screen, const std::string &name, unsigned id, Map::Map *map) :
	GameScene(screen, name, id),
	_map(map)
{
	this->_buttons.emplace_back(new Button({280, 150}, {20, 240, 110, 240 + 32}, RESUME, this->_window.getGuiEnv(), "RESUME"));
	this->_buttons.emplace_back(new Button({240, 170}, {20, 240, 110, 240 + 32}, SAVE_AND_EXIT, this->_window.getGuiEnv(), "SAVE AND QUIT"));
	this->_buttons.emplace_back(new Button({280, 490}, {20, 240, 110, 240 + 32}, PAUSE_EXIT, this->_window.getGuiEnv(), "QUIT"));

	this->_textBoxes.emplace_back(new TextBox({280, 25}, {20, 240, 110, 240 + 32}, 0, this->_window.getGuiEnv(), "PAUSE", true, true, true));
}

bool Irrlicht::PauseMenu::update()
{
	for (unsigned i = 0; i < this->_buttons.size(); i++) {
		if (this->isGuiButtonPressed(i)) {
			switch (i) {
				case RESUME:
					if (!this->_window.isValidGetterName("Game"))
						this->_window.addGameSceneGame("Game");
					changeCurrentGameScene("Game");
					break;
				case SAVE_AND_EXIT:
					this->_map->save("save.txt");
					this->_window.getDevice()->closeDevice();
					return (false);
				case PAUSE_EXIT:
					this->_window.getDevice()->closeDevice();
					return (false);
				default:
					break;
			}
			this->_window.resetButtonsStates();
		}
	}
	for (unsigned i = 0; i < this->_buttons.size(); i++)
		this->_buttons.at(i)->setVisible(true);
	for (unsigned i = 0; i < this->_textBoxes.size(); i++)
		this->_textBoxes.at(i)->setVisible(true);
	return (true);
}
