/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** LoadGameMenu.cpp
*/

#include "LoadGameMenu.hpp"

Irrlicht::LoadGameMenu::LoadGameMenu(Screen &screen, const std::string &name, unsigned id) :
    GameScene(screen, name, id)
{
	this->_buttons.emplace_back(new Button({200, 600}, {20, 240, 110, 240 + 32},LOAD_GAME_BACK, this->_window.getGuiEnv(), "BACK"));
	this->_buttons.emplace_back(new Button({350, 600}, {20, 240, 110, 240 + 32}, LOAD_GAME_NEXT, this->_window.getGuiEnv(), "NEXT"));
    this->_buttons.emplace_back(new Button({240, 290}, {20, 40, 60, 80}, SELECT_SLOT_LESS, this->_window.getGuiEnv(), "-"));
    this->_buttons.emplace_back(new Button({370, 290}, {20, 40, 60, 80}, SELECT_SLOT_MORE, this->_window.getGuiEnv(), "+"));

    this->_textBoxes.emplace_back(new TextBox({280, 25}, {20, 240, 110, 240 + 32}, 0, this->_window.getGuiEnv(), "LOAD GAME", true, true, true));
    this->_textBoxes.emplace_back(new TextBox({280, 150}, {20, 240, 110, 240 + 32}, 0, this->_window.getGuiEnv(), "Save's slot", true, true, true));
    this->_textBoxes.emplace_back(new TextBox({310, 300}, {15, 30, 45, 60}, 0, this->_window.getGuiEnv(), "0", true, true, true));
}

bool Irrlicht::LoadGameMenu::update()
{
    for (unsigned i = 0; i < this->_buttons.size(); i++)
        this->_buttons.at(i)->setVisible(true);
	for (unsigned i = 0; i < this->_buttons.size(); i++) {
        if (this->isGuiButtonPressed(i)) {
            for (unsigned i = 0; i < this->_buttons.size(); i++)
                this->_buttons.at(i)->setVisible(false);
            for (unsigned i = 0; i < this->_textBoxes.size(); i++)
                this->_textBoxes.at(i)->setVisible(false);
            switch (i) {
                case LOAD_GAME_BACK:
                    changeCurrentGameScene("MainMenu");
                    break;
                default:
                    break;
            }
        }
    }
	return (true);
}

void Irrlicht::LoadGameMenu::changeCurrentGameScene(std::string sceneName)
{
	this->_window.setCurrentGameScene(sceneName);
}