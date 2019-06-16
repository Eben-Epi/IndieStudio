/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** LoadGameMenu.cpp
*/

#include "SaveMenu.hpp"

Irrlicht::SaveMenu::SaveMenu(Screen &screen, const std::string &name, unsigned id, Map::Map *map) :
    GameScene(screen, name, id),
    _slotNumber(1),
    _map(map)
{
	this->_buttons.emplace_back(new Button({280, 550}, {20, 240, 110, 240 + 32},SAVE, this->_window.getGuiEnv(), "SAVE"));
    this->_buttons.emplace_back(new Button({240, 295}, {20, 40, 60, 80}, SAVE_MENU_LESS, this->_window.getGuiEnv(), "-"));
    this->_buttons.emplace_back(new Button({370, 295}, {20, 40, 60, 80}, SAVE_MENU_MORE, this->_window.getGuiEnv(), "+"));

    this->_textBoxes.emplace_back(new TextBox({280, 25}, {20, 240, 110, 240 + 32}, 0, this->_window.getGuiEnv(), "SAVE", true, true, true));
    this->_textBoxes.emplace_back(new TextBox({280, 235}, {20, 240, 110, 240 + 32}, 0, this->_window.getGuiEnv(), "Save's slot", true, true, true));
    this->_textBoxes.emplace_back(new TextBox({310, 300}, {15, 30, 45, 60}, 0, this->_window.getGuiEnv(), std::to_string(_slotNumber), true, true, true));
}

bool Irrlicht::SaveMenu::update()
{
	for (unsigned i = 0; i < this->_buttons.size(); i++) {
        if (this->isGuiButtonPressed(i)) {
            switch (i) {
                case SAVE_MENU_LESS:
                    if (this->_slotNumber >= 2) {
                        this->_slotNumber--;
                        this->_textBoxes[2]->setText(std::to_string(this->_slotNumber));
                    }
                    break;
                case SAVE_MENU_MORE:
                    if (this->_slotNumber <= 4) {
                        this->_slotNumber++;
                        this->_textBoxes[2]->setText(std::to_string(this->_slotNumber));
                    }
                    break;
                case SAVE:
                    this->_map->save("save"+ std::to_string(this->_slotNumber) + ".txt");
                    if (!this->_window.isValidGetterName("Game"))
                        this->_window.addGameSceneGame("Game");
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
