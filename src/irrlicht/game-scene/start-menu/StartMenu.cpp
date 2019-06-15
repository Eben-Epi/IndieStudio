/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** StartMenu.cpp
*/

#include "StartMenu.hpp"

Irrlicht::StartMenu::StartMenu(Screen &screen, const std::string &name, unsigned id) : GameScene(screen, name, id)
{
    this->_buttons.emplace_back(new Button({250, 600}, {20, 240, 110, 240 + 32}, BACK_FROM_NEW_GAME, this->_window.getGuiEnv(), "BACK"));
    this->_buttons.emplace_back(new Button({350, 600}, {20, 240, 110, 240 + 32}, NEXT_FROM_NEW_GAME, this->_window.getGuiEnv(), "NEXT"));
    this->_buttons.emplace_back(new Button({50, 100}, {20, 240, 110, 240 + 32}, SAVE_SLOT_LESS, this->_window.getGuiEnv(), "LESS"));
    this->_buttons.emplace_back(new Button({150, 100}, {20, 240, 110, 240 + 32}, SAVE_SLOT_MORE, this->_window.getGuiEnv(), "MORE"));
    this->_buttons.emplace_back(new Button({50, 500}, {20, 240, 110, 240 + 32}, NUMBER_OF_PLAYERS_LESS, this->_window.getGuiEnv(), "LESS"));
    this->_buttons.emplace_back(new Button({150, 500}, {20, 240, 110, 240 + 32}, NUMBER_OF_PLAYERS_MORE, this->_window.getGuiEnv(), "MORE"));

    // this->_buttons.emplace_back(new Button({280, 300}, {20, 240, 110, 240 + 32}, OPTIONS, this->_window.getGuiEnv(), "OPTIONS"));
	// this->_buttons.emplace_back(new Button({280, 500}, {20, 240, 110, 240 + 32}, EXIT, this->_window.getGuiEnv(), "EXIT"));

    this->_textBoxes.emplace_back(new TextBox({280, 25}, {20, 240, 110, 240 + 32}, 0, this->_window.getGuiEnv(), "GAME OPTIONS", true, true, true));
    this->_textBoxes.emplace_back(new TextBox({100, 75}, {20, 240, 110, 240 + 32}, 0, this->_window.getGuiEnv(), "SLOT", true, true, true));
    for (unsigned i = 0; i < this->_textBoxes.size(); i++)
        this->_textBoxes[i]->setTextAlignment(irr::gui::EGUIA_CENTER, irr::gui::EGUIA_CENTER);
}

bool Irrlicht::StartMenu::update()
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
                default:
                    break;
            }
        }
    }
	return (true);
}

void Irrlicht::StartMenu::changeCurrentGameScene(std::string sceneName)
{
	this->_window.setCurrentGameScene(sceneName);
}