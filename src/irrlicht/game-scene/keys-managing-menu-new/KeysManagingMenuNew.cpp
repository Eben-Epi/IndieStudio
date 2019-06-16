/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** KeysManagingMenuNew.cpp
*/

#include "KeysManagingMenuNew.hpp"

Irrlicht::KeysManagingMenuNew::KeysManagingMenuNew(Screen &screen, const std::string &name, unsigned id, unsigned playersNb, unsigned iaNb, unsigned soundVolume) :
	GameScene(screen, name, id), _playersNumber(playersNb), _iaNumber(iaNb), _soundVolume(soundVolume)
{
    this->_textBoxes.emplace_back(new TextBox({280, 25}, {20, 240, 110, 240 + 32}, 0, this->_window.getGuiEnv(), "CHANGE KEYS", true, true, true));
	//afficher du text qui représente chaque player en colonne et chaque key en lignes

	// EXPLANATION

    this->_textBoxes.emplace_back(new TextBox({10, 200}, {20, 220, 80, 220 + 32}, 0, this->_window.getGuiEnv(), "UP"));
    this->_textBoxes.emplace_back(new TextBox({10, 260}, {20, 220, 80, 220 + 32}, 0, this->_window.getGuiEnv(), "DOWN"));
    this->_textBoxes.emplace_back(new TextBox({10, 320}, {20, 220, 80, 220 + 32}, 0, this->_window.getGuiEnv(), "LEFT"));
    this->_textBoxes.emplace_back(new TextBox({10, 380}, {20, 220, 80, 220 + 32}, 0, this->_window.getGuiEnv(), "RIGHT"));
    this->_textBoxes.emplace_back(new TextBox({10, 440}, {20, 220, 80, 220 + 32}, 0, this->_window.getGuiEnv(), "DROP"));
    this->_textBoxes.emplace_back(new TextBox({10, 500}, {20, 220, 80, 220 + 32}, 0, this->_window.getGuiEnv(), "ULT"));

	// KEYS
	for (int i = 0; i != _playersNumber; i++) {
        this->_textBoxes.emplace_back(new TextBox({100 + ((double)i * 120), 140}, {20, 240, 110, 240 + 32}, 0, this->_window.getGuiEnv(), "Player " + std::to_string(i + 1), true, true, true));
        this->_buttons.emplace_back(new Button({100 + ((double)i * 120), 200}, {20, 240, 110, 240 + 32}, Input::P1_UP + (i * 6),
                                               this->_window.getGuiEnv(), "UP"));
        this->_buttons.emplace_back(new Button({100 + ((double)i * 120), 260}, {20, 240, 110, 240 + 32}, Input::P1_DOWN + (i * 6),
                                               this->_window.getGuiEnv(), "DOWN"));
        this->_buttons.emplace_back(new Button({100 + ((double)i * 120), 320}, {20, 240, 110, 240 + 32}, Input::P1_LEFT + (i * 6),
                                               this->_window.getGuiEnv(), "LEFT"));
        this->_buttons.emplace_back(new Button({100 + ((double)i * 120), 380}, {20, 240, 110, 240 + 32}, Input::P1_RIGHT + (i * 6),
                                               this->_window.getGuiEnv(), "RIGHT"));
        this->_buttons.emplace_back(new Button({100 + ((double)i * 120), 440}, {20, 240, 110, 240 + 32}, Input::P1_DROP + (i * 6),
                                               this->_window.getGuiEnv(), "DROP"));
        this->_buttons.emplace_back(new Button({100 + ((double)i * 120), 500}, {20, 240, 110, 240 + 32}, Input::P1_ULT + (i * 6),
                                               this->_window.getGuiEnv(), "ULT"));
    }
    this->_buttons.emplace_back(new Button({200, 550}, {20, 240, 110, 240 + 32}, Input::BACK_FROM_KEYS_MANAGING, this->_window.getGuiEnv(), "BACK"));
    this->_buttons.emplace_back(new Button({350, 550}, {20, 240, 110, 240 + 32}, Input::NEXT_FROM_KEYS_MANAGING, this->_window.getGuiEnv(), "NEXT"));

}

bool Irrlicht::KeysManagingMenuNew::update()
{
	for (unsigned i = 0; i < this->_buttons.size() - 1; i++) {
		if (this->isGuiButtonPressed(i)) {
			switch (i) {
			case Input::BACK_FROM_KEYS_MANAGING:
				if (!this->_window.isValidGetterName("Main Menu"))
					this->_window.addGameSceneMainMenu("Main Menu");
				changeCurrentGameScene("Main Menu");
				return (false);
			case Input::NEXT_FROM_KEYS_MANAGING:
				if (!this->_window.isValidGetterName("Game"))
					this->_window.addGameSceneGame("Game");
				changeCurrentGameScene("Game");
				return (true);
			default:
				break;
			}
		}
		this->_window.resetButtonsStates();
	}
	for (unsigned i = 0; i < this->_buttons.size(); i++)
		this->_buttons.at(i)->setVisible(true);
	for (unsigned i = 0; i < this->_textBoxes.size(); i++)
		this->_textBoxes.at(i)->setVisible(true);
	return (true);
}