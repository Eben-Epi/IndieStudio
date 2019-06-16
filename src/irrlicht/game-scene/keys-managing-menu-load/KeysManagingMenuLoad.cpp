/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** KeysManagingMenuLoad.cpp
*/

#include "KeysManagingMenuLoad.hpp"

Irrlicht::KeysManagingMenuLoad::KeysManagingMenuLoad(Screen &screen, const std::string &name, unsigned id, unsigned playersNb, unsigned iaNb, unsigned soundVolume) :
        GameScene(screen, name, id), _playersNumber(playersNb), _iaNumber(iaNb), _soundVolume(soundVolume)
{
    //afficher du text qui représente chaque player en colonne et chaque key en lignes
    this->_buttons.emplace_back(new Button({200, 550}, {20, 240, 110, 240 + 32}, Input::BACK_FROM_KEYS_MANAGING, this->_window.getGuiEnv(), "BACK"));
    this->_buttons.emplace_back(new Button({350, 550}, {20, 240, 110, 240 + 32}, Input::NEXT_FROM_KEYS_MANAGING, this->_window.getGuiEnv(), "NEXT"));

    //Player 1
    this->_buttons.emplace_back(new Button({150, 200}, {20, 240, 110, 240 + 32}, Input::P1_UP, this->_window.getGuiEnv(), "UP"));
    this->_buttons.emplace_back(new Button({150, 260}, {20, 240, 110, 240 + 32}, Input::P1_DOWN, this->_window.getGuiEnv(), "DOWN"));
    this->_buttons.emplace_back(new Button({150, 320}, {20, 240, 110, 240 + 32}, Input::P1_LEFT, this->_window.getGuiEnv(), "LEFT"));
    this->_buttons.emplace_back(new Button({150, 380}, {20, 240, 110, 240 + 32}, Input::P1_RIGHT, this->_window.getGuiEnv(), "RIGHT"));
    this->_buttons.emplace_back(new Button({150, 440}, {20, 240, 110, 240 + 32}, Input::P1_DROP, this->_window.getGuiEnv(), "DROP"));
    this->_buttons.emplace_back(new Button({150, 500}, {20, 240, 110, 240 + 32}, Input::P1_ULT, this->_window.getGuiEnv(), "ULT"));
    this->_textBoxes.emplace_back(new TextBox({280, 25}, {20, 240, 110, 240 + 32}, 0, this->_window.getGuiEnv(), "CHANGE KEYS", true, true, true));
}

bool Irrlicht::KeysManagingMenuLoad::update()
{
    for (unsigned i = 0; i < this->_buttons.size() - 1; i++) {
        if (this->isGuiButtonPressed(i)) {
            switch (i) {
                case Input::BACK_FROM_KEYS_MANAGING:
                    if (!this->_window.isValidGetterName("Main Menu"))
                        this->_window.addGameSceneMainMenu("Main Menu");
                    changeCurrentGameScene("Main Menu");
                    return (true);
                case Input::NEXT_FROM_KEYS_MANAGING:
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