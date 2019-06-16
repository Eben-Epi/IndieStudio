//
// Created by eben_epitech on 6/15/19.
//

#include "NewGameMenu.hpp"

Irrlicht::NewGameMenu::NewGameMenu(Screen &screen, const std::string &name, unsigned id) :
        GameScene(screen, name, id), _playersNumber(1), _soundVolume(5), _tmpSoundVolume(5), _iaNumber(1)
{
    //TITLE
    this->_textBoxes.emplace_back(new TextBox({280, 5}, {20, 240, 110, 240 + 32}, 0, this->_window.getGuiEnv(), "GAME OPTIONS", true, true, true));

    //NUMBER OF PLAYERS
    this->_textBoxes.emplace_back(new TextBox({280, 50}, {20, 240, 110, 240 + 32}, 0, this->_window.getGuiEnv(), "NUMBER OF PLAYERS", true, true, true));
    this->_buttons.emplace_back(new Button({190, 110}, {20, 120, 110, 120 + 32}, NUMBER_OF_PLAYERS_LESS, this->_window.getGuiEnv(), "LESS"));
    this->_textBoxes.emplace_back(new TextBox({315, 115}, {10, 20, 30, 40}, 0, this->_window.getGuiEnv(), std::to_string(this->_playersNumber), true, true, true));
    this->_buttons.emplace_back(new Button({370, 110}, {20, 120, 110, 120 + 32}, NUMBER_OF_PLAYERS_MORE, this->_window.getGuiEnv(), "MORE"));

    //NUMBER OF IAs
    this->_textBoxes.emplace_back(new TextBox({280, 140}, {20, 240, 110, 240 + 32}, 0, this->_window.getGuiEnv(), "NUMBER OF IAs", true, true, true));
    this->_buttons.emplace_back(new Button({190, 200}, {20, 120, 110, 120 + 32}, NUMBER_OF_AI_LESS, this->_window.getGuiEnv(), "LESS"));
    this->_textBoxes.emplace_back(new TextBox({315, 175}, {10, 20, 30, 40}, 0, this->_window.getGuiEnv(), std::to_string(this->_iaNumber), true, true, true));
    this->_buttons.emplace_back(new Button({370, 200}, {20, 120, 110, 120 + 32}, NUMBER_OF_AI_MORE, this->_window.getGuiEnv(), "MORE"));

    //NUMBER OF SOUND VOLUME
    this->_textBoxes.emplace_back(new TextBox({280, 340}, {20, 240, 110, 240 + 32}, 0, this->_window.getGuiEnv(), "SOUND VOLUME", true, true, true));
    this->_buttons.emplace_back(new Button({190, 400}, {20, 120, 110, 120 + 32}, SOUND_LESS, this->_window.getGuiEnv(), "LESS"));
    this->_textBoxes.emplace_back(new TextBox({315, 405}, {10, 20, 30, 40}, 0, this->_window.getGuiEnv(), std::to_string(this->_soundVolume), true, true, true));
    this->_buttons.emplace_back(new Button({370, 400}, {20, 120, 110, 120 + 32}, SOUND_MORE, this->_window.getGuiEnv(), "MORE"));
    this->_buttons.emplace_back(new Button({280, 460}, {20, 120, 110, 120 + 32}, SOUND_MUTE, this->_window.getGuiEnv(), "MUTE"));

    //BACK TO MAIN MENU && AND GO TO INPUT MENU
    this->_buttons.emplace_back(new Button({350, 550}, {20, 120, 110, 120 + 32}, NEXT_FROM_NEW_GAME, this->_window.getGuiEnv(), "NEXT"));
    this->_buttons.emplace_back(new Button({210, 550}, {20, 120, 110, 120 + 32}, BACK_FROM_NEW_GAME, this->_window.getGuiEnv(), "BACK"));
}

bool Irrlicht::NewGameMenu::update()
{
    for (unsigned i = 0; i < this->_buttons.size(); i++) {
        if (this->isGuiButtonPressed(i)) {
            switch (i) {
                case NUMBER_OF_PLAYERS_LESS:
                    if (this->_playersNumber > 0 && this->_playersNumber + this->_iaNumber > 1) {
                        this->_playersNumber--;
                        this->_textBoxes[2]->setText(std::to_string(this->_playersNumber));
                    }
                    break;
                case NUMBER_OF_PLAYERS_MORE:
                    if (this->_iaNumber + this->_playersNumber < 4) {
                        this->_playersNumber++;
                        this->_textBoxes[2]->setText(std::to_string(this->_playersNumber));
                    }
                    break;
                case SOUND_LESS:
                    if (this->_soundVolume >= 1) {
                        this->_soundVolume--;
                        this->_textBoxes[6]->setText(std::to_string(this->_soundVolume));
                    }
                    break;
                case SOUND_MORE:
                    if (this->_soundVolume < 10) {
                        this->_soundVolume++;
                        this->_textBoxes[6]->setText(std::to_string(this->_soundVolume));
                    }
                    break;
                case SOUND_MUTE:
                    if (this->_soundVolume > 0) {
                        this->_tmpSoundVolume = this->_soundVolume;
                        this->_soundVolume = 0;
                    } else
                        this->_soundVolume = this->_tmpSoundVolume;
                    this->_textBoxes[6]->setText(std::to_string(this->_soundVolume));
                    break;
                case NUMBER_OF_AI_LESS:
                    if (this->_iaNumber > 0 && this->_playersNumber + this->_iaNumber > 1) {
                        this->_iaNumber--;
                        this->_textBoxes[4]->setText(std::to_string(this->_iaNumber));
                    }
                    break;
                case NUMBER_OF_AI_MORE:
                    if (this->_iaNumber + this->_playersNumber < 4) {
                        this->_iaNumber++;
                        this->_textBoxes[4]->setText(std::to_string(this->_iaNumber));
                    }
                    break;
                case BACK_FROM_NEW_GAME:
                    if (!this->_window.isValidGetterName("Main Menu"))
                        this->_window.addGameSceneMainMenu("Main Menu");
                    changeCurrentGameScene("Main Menu");
                    return (true);
                case NEXT_FROM_NEW_GAME:
                    if (!this->_window.isValidGetterName("Input Menu"))
                        this->_window.addGameSceneMainMenu("Input Menu");
                    changeCurrentGameScene("Input Menu");
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
    for (unsigned i = 0; i < this->_textBoxes.size(); i++)
        this->_textBoxes[i]->setTextAlignment(irr::gui::EGUIA_CENTER, irr::gui::EGUIA_CENTER);
    return (true);
}
