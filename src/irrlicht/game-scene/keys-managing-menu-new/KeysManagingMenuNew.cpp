/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** KeysManagingMenuNew.cpp
*/

#include <search.h>
#include "KeysManagingMenuNew.hpp"
#include "../../../input/Keyboard.hpp"
#include "../../../input/Controller.hpp"

static std::vector<Input::ControllerButtons> defaultController = {
        Input::LEFT_JOYSTICK,
        Input::B,
        Input::A
};

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

Irrlicht::KeysManagingMenuNew::KeysManagingMenuNew(Screen &screen, const std::string &name, unsigned id, unsigned playersNb, unsigned iaNb, unsigned soundVolume) :
	GameScene(screen, name, id), _playersNumber(playersNb), _iaNumber(iaNb), _soundVolume(soundVolume)
{
    this->_textBoxes.emplace_back(new TextBox({280, 25}, {20, 240, 110, 240 + 32}, 0, this->_window.getGuiEnv(), "CHANGE KEYS", true, true, true));
	//afficher du text qui représente chaque player en colonne et chaque key en lignes

	if (this->_window.getDevice()->activateJoysticks(this->_joystickInfos)) {
        std::cout << "Joystick support is enabled and " << this->_joystickInfos.size() << " joystick(s) are present." << std::endl;
    }
	// EXPLANATION

    this->_textBoxes.emplace_back(new TextBox({30, 200}, {20, 220, 80, 220 + 32}, 0, this->_window.getGuiEnv(), "UP"));
    this->_textBoxes.emplace_back(new TextBox({30, 260}, {20, 220, 80, 220 + 32}, 0, this->_window.getGuiEnv(), "DOWN"));
    this->_textBoxes.emplace_back(new TextBox({30, 320}, {20, 220, 80, 220 + 32}, 0, this->_window.getGuiEnv(), "LEFT"));
    this->_textBoxes.emplace_back(new TextBox({30, 380}, {20, 220, 80, 220 + 32}, 0, this->_window.getGuiEnv(), "RIGHT"));
    this->_textBoxes.emplace_back(new TextBox({30, 440}, {20, 220, 80, 220 + 32}, 0, this->_window.getGuiEnv(), "DROP"));
    this->_textBoxes.emplace_back(new TextBox({30, 500}, {20, 220, 80, 220 + 32}, 0, this->_window.getGuiEnv(), "ULT"));

    this->_buttons.emplace_back(new Button({200, 550}, {20, 240, 110, 240 + 32}, Input::BACK_FROM_KEYS_MANAGING, this->_window.getGuiEnv(), "BACK"));
    this->_buttons.emplace_back(new Button({350, 550}, {20, 240, 110, 240 + 32}, Input::NEXT_FROM_KEYS_MANAGING, this->_window.getGuiEnv(), "NEXT"));
	// KEYS
	for (int i = 0; i != _playersNumber; i++) {
        if (this->_joystickInfos.size() > i) {
            this->_inputs.emplace_back(new Input::Controller(*this, defaultController, i));
            this->_isPlayerJoystick.push_back(i + 1);
            this->_buttons.emplace_back(new Button({120 + ((double) i * 120), 80}, {20, 240, 110, 240 + 32}, Input::P1_INPUT_CHOICE + i, this->_window.getGuiEnv(), "JOYSTICK " + std::to_string(i)));
        } else {
            this->_inputs.emplace_back(new Input::Keyboard(*this, defaultKeyboardsKeys[i]));
            this->_isPlayerJoystick.push_back(0);
            this->_buttons.emplace_back(new Button({120 + ((double) i * 120), 80}, {20, 240, 110, 240 + 32}, Input::P1_INPUT_CHOICE + i, this->_window.getGuiEnv(), "KEYBOARD"));
        }
        this->_textBoxes.emplace_back(new TextBox({120 + ((double)i * 120), 140}, {20, 240, 110, 240 + 32}, 0, this->_window.getGuiEnv(), "Player " + std::to_string(i + 1), true, true, true));
        this->_buttons.emplace_back(new Button({120 + ((double)i * 120), 200}, {20, 240, 110, 240 + 32}, Input::P1_UP + (i * 6),
                                               this->_window.getGuiEnv(), this->_inputs.back()->getEnumControlString(Input::ACTION_UP)));
        this->_buttons.emplace_back(new Button({120 + ((double)i * 120), 260}, {20, 240, 110, 240 + 32}, Input::P1_DOWN + (i * 6),
                                               this->_window.getGuiEnv(), this->_inputs.back()->getEnumControlString(Input::ACTION_DOWN)));
        this->_buttons.emplace_back(new Button({120 + ((double)i * 120), 320}, {20, 240, 110, 240 + 32}, Input::P1_LEFT + (i * 6),
                                               this->_window.getGuiEnv(), this->_inputs.back()->getEnumControlString(Input::ACTION_LEFT)));
        this->_buttons.emplace_back(new Button({120 + ((double)i * 120), 380}, {20, 240, 110, 240 + 32}, Input::P1_RIGHT + (i * 6),
                                               this->_window.getGuiEnv(), this->_inputs.back()->getEnumControlString(Input::ACTION_RIGHT)));
        this->_buttons.emplace_back(new Button({120 + ((double)i * 120), 440}, {20, 240, 110, 240 + 32}, Input::P1_DROP + (i * 6),
                                               this->_window.getGuiEnv(), this->_inputs.back()->getEnumControlString(Input::ACTION_ACTION)));
        this->_buttons.emplace_back(new Button({120 + ((double)i * 120), 500}, {20, 240, 110, 240 + 32}, Input::P1_ULT + (i * 6),
                                               this->_window.getGuiEnv(), this->_inputs.back()->getEnumControlString(Input::ACTION_ULT)));
    }
}


bool Irrlicht::KeysManagingMenuNew::update()
{
    std::vector<Map::Map::PlayerConfig> configs;
    auto key = irr::KEY_KEY_CODES_COUNT;
    for (unsigned i = 0; i < this->_buttons.size(); i++) {
        if (this->isGuiButtonPressed(this->_buttons[i]->id)) {
            auto &button = this->_buttons[i];
            auto inputId = (button->id - Input::P1_UP) / (Input::P2_UP - Input::P1_UP);
            auto actionId = (button->id - Input::P1_UP) % (Input::P2_UP - Input::P1_UP);
            auto &input = this->_inputs[inputId];

			switch (button->id) {
                case Input::P1_UP:
                case Input::P1_DOWN:
                case Input::P1_LEFT:
                case Input::P1_RIGHT:
                case Input::P1_DROP:
                case Input::P1_ULT:
                case Input::P2_UP:
                case Input::P2_DOWN:
                case Input::P2_LEFT:
                case Input::P2_RIGHT:
                case Input::P2_DROP:
                case Input::P2_ULT:
                case Input::P3_UP:
                case Input::P3_DOWN:
                case Input::P3_LEFT:
                case Input::P3_RIGHT:
                case Input::P3_DROP:
                case Input::P3_ULT:
                case Input::P4_UP:
                case Input::P4_DOWN:
                case Input::P4_LEFT:
                case Input::P4_RIGHT:
                case Input::P4_DROP:
                case Input::P4_ULT:
                    if (!_isPlayerJoystick[inputId]) {
                        for (; key == irr::KEY_KEY_CODES_COUNT; key = this->_window.getEventReceiver().returnNextKeyPressed()) {
                            this->_window.getDevice()->run();
                        }
                        if (key != irr::KEY_ESCAPE) {
                            reinterpret_cast<Input::Keyboard&>(*input).changeKey(
                                static_cast<Input::Action>(
                                    actionId
                                ), key
                            );
                            button->setText(
                                input->getEnumControlString(
                                    static_cast<Input::Action>(
                                        actionId
                                    )
                                )
                            );
                        }
                    }
                    break;
                case Input::P1_INPUT_CHOICE:
                case Input::P2_INPUT_CHOICE:
                case Input::P3_INPUT_CHOICE:
                case Input::P4_INPUT_CHOICE:
                    this->assignNextJoystick(button->id - Input::P1_INPUT_CHOICE);
                    if (this->_isPlayerJoystick[button->id - Input::P1_INPUT_CHOICE]) {
                        button->setText("JOYSTICK " + std::to_string(this->_isPlayerJoystick[button->id - Input::P1_INPUT_CHOICE] - 1));
                        this->_inputs[button->id - Input::P1_INPUT_CHOICE].reset(new Input::Controller(*this, defaultController, button->id - Input::P1_INPUT_CHOICE));
                    } else {
                        button->setText("KEYBOARD");
                        this->_inputs[button->id - Input::P1_INPUT_CHOICE].reset(new Input::Keyboard(*this, defaultKeyboardsKeys[button->id - Input::P1_INPUT_CHOICE]));
                    }
                    for (int ac = Input::ACTION_UP; ac < Input::NB_OF_ACTIONS; ac++)
                        this->_buttons[i + ac + 1]->setText(this->_inputs[button->id - Input::P1_INPUT_CHOICE]->getEnumControlString(static_cast<Input::Action>(ac)));
                    break;
                case Input::BACK_FROM_KEYS_MANAGING:
                    if (!this->_window.isValidGetterName("Main Menu"))
                        this->_window.addGameSceneMainMenu("Main Menu");
                    changeCurrentGameScene("Main Menu");
                    return (false);
                case Input::NEXT_FROM_KEYS_MANAGING:
                    for (unsigned j = 0; j != this->_playersNumber; j++) {
                        configs.push_back(Map::Map::PlayerConfig{&*this->_inputs[j], playerEntities[rand() % playerEntities.size()], j});
                    }
                    for (unsigned j = 0; j != this->_iaNumber; j++) {
                        configs.push_back(Map::Map::PlayerConfig{nullptr, playerEntities[rand() % playerEntities.size()], j + this->_playersNumber});
                    }
                    if (!this->_window.isValidGetterName("Game"))
                        this->_window.addGameSceneGame("Game", configs);
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



unsigned Irrlicht::KeysManagingMenuNew::joysticksAvailable() {
    unsigned available = this->_joystickInfos.size();

    for (size_t i = 0; i != this->_isPlayerJoystick.size(); i++)
        if (this->_isPlayerJoystick[i])
            available--;
    return (available);
}

void Irrlicht::KeysManagingMenuNew::assignNextJoystick(unsigned player) {
    for (size_t i = 0; i != this->_isPlayerJoystick.size(); i++) {
        if (i == player) {
            this->_isPlayerJoystick[i]++;
            this->_isPlayerJoystick[i] %= this->_joystickInfos.size() + 1;
            return;
        }
    }
}

