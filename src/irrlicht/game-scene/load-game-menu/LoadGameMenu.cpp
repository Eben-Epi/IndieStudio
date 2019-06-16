/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** LoadGameMenu.cpp
*/

#include "LoadGameMenu.hpp"
#include "../../../input/Keyboard.hpp"
#include "../keys-managing-menu-new/KeysManagingMenuNew.hpp"


Irrlicht::LoadGameMenu::LoadGameMenu(Screen &screen, const std::string &name, unsigned id) :
    GameScene(screen, name, id), _slotNumber(1)
{
	this->_buttons.emplace_back(new Button({200, 550}, {20, 240, 110, 240 + 32},LOAD_GAME_BACK, this->_window.getGuiEnv(), "BACK"));
	this->_buttons.emplace_back(new Button({350, 550}, {20, 240, 110, 240 + 32}, LOAD_GAME_NEXT, this->_window.getGuiEnv(), "NEXT"));
    this->_buttons.emplace_back(new Button({240, 295}, {20, 40, 60, 80}, SELECT_SLOT_LESS, this->_window.getGuiEnv(), "-"));
    this->_buttons.emplace_back(new Button({370, 295}, {20, 40, 60, 80}, SELECT_SLOT_MORE, this->_window.getGuiEnv(), "+"));

    this->_textBoxes.emplace_back(new TextBox({280, 25}, {20, 240, 110, 240 + 32}, 0, this->_window.getGuiEnv(), "LOAD GAME", true, true, true));
    this->_textBoxes.emplace_back(new TextBox({280, 235}, {20, 240, 110, 240 + 32}, 0, this->_window.getGuiEnv(), "Save's slot", true, true, true));
    this->_textBoxes.emplace_back(new TextBox({310, 300}, {15, 30, 45, 60}, 0, this->_window.getGuiEnv(), std::to_string(_slotNumber), true, true, true));

}

bool Irrlicht::LoadGameMenu::update()
{
    for (unsigned i = 0; i < this->_buttons.size(); i++) {
        if (this->isGuiButtonPressed(i)) {
            switch (i) {
                case SELECT_SLOT_LESS:
                    if (this->_slotNumber >= 2) {
                        this->_slotNumber--;
                        this->_textBoxes[2]->setText(std::to_string(this->_slotNumber));
                    }
                    break;
                case SELECT_SLOT_MORE:
                    if (this->_slotNumber <= 4) {
                        this->_slotNumber++;
                        this->_textBoxes[2]->setText(std::to_string(this->_slotNumber));
                    }
                    break;
                case LOAD_GAME_NEXT:
                    if (!this->_window.isValidGetterName("Keys Managing Menu"))
                        this->_window.addGameSceneKeysManagingMenuLoad("Keys Managing Menu", 1, 1, 5);
                    changeCurrentGameScene("Keys Managing Menu");
                    return (true);
                case LOAD_GAME_BACK:
                    if (!this->_window.isValidGetterName("Game"))
                        this->_window.addGameSceneGame("Game", this->_inputs, "save.txt");
                    changeCurrentGameScene("Game");
                    return (true);
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
