/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** TextBox.cpp
*/

#include <iostream>
#include "TextBox.hpp"

Irrlicht::TextBox::TextBox(ECS::Point pos, ECS::Vector4<int> size, unsigned id, irr::gui::IGUIEnvironment *guienv, std::string text, \
bool border, bool worlWrap, bool fillBackground, irr::gui::EGUI_ALIGNMENT horizontal, irr::gui::EGUI_ALIGNMENT vertical) :
    id(id),
    _pos({0, 0}),
    _size(size),
    _guienv(guienv),
    _visible(true),
    _border(border),
    _worldWrap(worlWrap),
    _fillbackground(fillBackground),
    _vertical(vertical),
    _horizontal(horizontal),
    _color(irr::video::SColor(255, 0, 0, 0)),
    _backgroundColor(irr::video::SColor(255, 150, 150, 150))
{
    wchar_t *val = reinterpret_cast<wchar_t *>(malloc(sizeof(*val) * (text.size() + 1)));

    for (size_t i = 0; i < text.size(); i++)
        val[i] = text[i];
    val[text.size()] = 0;
    if (!text.empty()) {
        this->_text = text;
        this->_textBox = this->_guienv->addStaticText(\
            val, irr::core::rect<irr::s32>(_size.a, _size.b, _size.c, _size.d), \
            this->_border, this->_worldWrap, 0, this->id, this->_fillbackground);
    } else
        this->_textBox = this->_guienv->addStaticText(\
            reinterpret_cast<const wchar_t *>(&this->_text), irr::core::rect<irr::s32>(_size.a, _size.b, _size.c, _size.d), \
            this->_border, this->_worldWrap, 0, this->id, this->_fillbackground);
    free(val);
    this->setBackgroundColor(this->_backgroundColor);
    this->setColorOfText(this->_color);
    this->setTextAlignment(this->_horizontal, this->_vertical);
    this->setPos(pos);
}

const std::string &Irrlicht::TextBox::getText()
{
    return this->_text;
}

const ECS::Point &Irrlicht::TextBox::getPos()
{
    return this->_pos;
}

const ECS::Vector4<int> &Irrlicht::TextBox::getSize()
{
    return this->_size;
}

void Irrlicht::TextBox::setText(std::string text)
{
    this->_textBox->remove();
    wchar_t *val = reinterpret_cast<wchar_t *>(malloc(sizeof(*val) * (text.size() + 1)));

    for (size_t i = 0; i < text.size(); i++)
        val[i] = text[i];
    val[text.size()] = 0;
    if (!text.empty()) {
        this->_text = text;
        this->_textBox = this->_guienv->addStaticText(
            val, irr::core::rect<irr::s32>(_size.a, _size.b, _size.c, _size.d),
            this->_border, this->_worldWrap, 0, this->id, this->_fillbackground);
    } else
        this->_textBox = this->_guienv->addStaticText(
            reinterpret_cast<const wchar_t *>(&this->_text), irr::core::rect<irr::s32>(_size.a, _size.b, _size.c, _size.d),
            this->_border, this->_worldWrap, 0, this->id, this->_fillbackground);
    free(val);
    this->setBackgroundColor(this->_backgroundColor);
    this->setColorOfText(this->_color);
    this->setTextAlignment(this->_horizontal, this->_vertical);
    this->setPos(this->_pos);
}

void Irrlicht::TextBox::setPos(ECS::Point pos)
{
    this->_pos = pos;
    this->_textBox->setRelativePosition(irr::core::position2di((int)_pos.x, (int)_pos.y));
}

void Irrlicht::TextBox::setSize(ECS::Vector4<int> size)
{
    this->_textBox->remove();
    this->_size = size;
    this->_textBox = this->_guienv->addStaticText(
        reinterpret_cast<const wchar_t *>(&this->_text), irr::core::rect<irr::s32>(_size.a, _size.b, _size.c, _size.d),
        this->_border, this->_worldWrap, 0, this->id, this->_fillbackground);
    this->setBackgroundColor(this->_backgroundColor);
    this->setColorOfText(this->_color);
    this->setTextAlignment(this->_horizontal, this->_vertical);
    this->setPos(this->_pos);
    return;
}

void Irrlicht::TextBox::setVisible(bool visible)
{
	if (this->_visible == visible)
		return;
	this->_visible = visible;
    this->_textBox->setVisible(visible);
}

void Irrlicht::TextBox::setBackgroundColor(irr::video::SColor color)
{
    this->_backgroundColor = color;
    this->_textBox->setBackgroundColor(color);
}

void Irrlicht::TextBox::setDrawBackground(bool draw)
{
    this->_textBox->setDrawBackground(draw);
}

void Irrlicht::TextBox::setDrawBorder(bool draw)
{
    this->_textBox->setDrawBorder(draw);
}

void Irrlicht::TextBox::setTextAlignment(irr::gui::EGUI_ALIGNMENT horizontal, irr::gui::EGUI_ALIGNMENT vertical)
{
    this->_horizontal = horizontal;
    this->_vertical = vertical;
    this->_textBox->setTextAlignment(horizontal, vertical);
}

void Irrlicht::TextBox::setColorOfText(irr::video::SColor color)
{
    this->_color = color;
    this->_textBox->setOverrideColor(color);
}

std::map<irr::EKEY_CODE, std::string> Irrlicht::ekey_code_str = {
    {irr::EKEY_CODE::KEY_LBUTTON, "LBUTTON"},
    {irr::EKEY_CODE::KEY_RBUTTON, "RBUTTON"},
    {irr::EKEY_CODE::KEY_CANCEL, "CANCEL"},
    {irr::EKEY_CODE::KEY_MBUTTON, "MBUTTON"},
    {irr::EKEY_CODE::KEY_XBUTTON1, "XBUTTON1"},
    {irr::EKEY_CODE::KEY_XBUTTON2, "XBUTTON2"},
    {irr::EKEY_CODE::KEY_BACK, "BACK"},
    {irr::EKEY_CODE::KEY_TAB, "TAB"},
    {irr::EKEY_CODE::KEY_CLEAR, "CLEAR"},
    {irr::EKEY_CODE::KEY_RETURN, "RETURN"},
    {irr::EKEY_CODE::KEY_SHIFT, "SHIFT"},
    {irr::EKEY_CODE::KEY_CONTROL, "CONTROL"},
    {irr::EKEY_CODE::KEY_MENU, "MENU"},
    {irr::EKEY_CODE::KEY_PAUSE, "PAUSE"},
    {irr::EKEY_CODE::KEY_CAPITAL, "CAPITAL"},
    {irr::EKEY_CODE::KEY_KANA, "KANA"},
    {irr::EKEY_CODE::KEY_HANGUEL, "HANGUEL"},
    {irr::EKEY_CODE::KEY_HANGUL, "HANGUL"},
    {irr::EKEY_CODE::KEY_JUNJA, "JUNJA"},
    {irr::EKEY_CODE::KEY_FINAL, "FINAL"},
    {irr::EKEY_CODE::KEY_HANJA, "HANJA"},
    {irr::EKEY_CODE::KEY_KANJI, "KANJI"},
    {irr::EKEY_CODE::KEY_ESCAPE, "ESCAPE"},
    {irr::EKEY_CODE::KEY_CONVERT, "CONVERT"},
    {irr::EKEY_CODE::KEY_NONCONVERT, "NONCONVERT"},
    {irr::EKEY_CODE::KEY_ACCEPT, "ACCEPT"},
    {irr::EKEY_CODE::KEY_MODECHANGE, "MODECHANGE"},
    {irr::EKEY_CODE::KEY_SPACE, "SPACE"},
    {irr::EKEY_CODE::KEY_PRIOR, "PRIOR"},
    {irr::EKEY_CODE::KEY_NEXT, "NEXT"},
    {irr::EKEY_CODE::KEY_END, "END"},
    {irr::EKEY_CODE::KEY_HOME, "HOME"},
    {irr::EKEY_CODE::KEY_LEFT, "LEFT"},
    {irr::EKEY_CODE::KEY_UP, "UP"},
    {irr::EKEY_CODE::KEY_RIGHT, "RIGHT"},
    {irr::EKEY_CODE::KEY_DOWN, "DOWN"},
    {irr::EKEY_CODE::KEY_SELECT, "SELECT"},
    {irr::EKEY_CODE::KEY_PRINT, "PRINT"},
    {irr::EKEY_CODE::KEY_EXECUT, "EXECUT"},
    {irr::EKEY_CODE::KEY_SNAPSHOT, "SNAPSHOT"},
    {irr::EKEY_CODE::KEY_INSERT, "INSERT"},
    {irr::EKEY_CODE::KEY_DELETE, "DELETE"},
    {irr::EKEY_CODE::KEY_HELP, "HELP"},
    {irr::EKEY_CODE::KEY_KEY_0, "0"},
    {irr::EKEY_CODE::KEY_KEY_1, "1"},
    {irr::EKEY_CODE::KEY_KEY_2, "2"},
    {irr::EKEY_CODE::KEY_KEY_3, "3"},
    {irr::EKEY_CODE::KEY_KEY_4, "4"},
    {irr::EKEY_CODE::KEY_KEY_5, "5"},
    {irr::EKEY_CODE::KEY_KEY_6, "6"},
    {irr::EKEY_CODE::KEY_KEY_7, "7"},
    {irr::EKEY_CODE::KEY_KEY_8, "8"},
    {irr::EKEY_CODE::KEY_KEY_9, "9"},
    {irr::EKEY_CODE::KEY_KEY_A, "A"},
    {irr::EKEY_CODE::KEY_KEY_B, "B"},
    {irr::EKEY_CODE::KEY_KEY_C, "C"},
    {irr::EKEY_CODE::KEY_KEY_D, "D"},
    {irr::EKEY_CODE::KEY_KEY_E, "E"},
    {irr::EKEY_CODE::KEY_KEY_F, "F"},
    {irr::EKEY_CODE::KEY_KEY_G, "G"},
    {irr::EKEY_CODE::KEY_KEY_H, "H"},
    {irr::EKEY_CODE::KEY_KEY_I, "I"},
    {irr::EKEY_CODE::KEY_KEY_J, "J"},
    {irr::EKEY_CODE::KEY_KEY_K, "K"},
    {irr::EKEY_CODE::KEY_KEY_L, "L"},
    {irr::EKEY_CODE::KEY_KEY_M, "M"},
    {irr::EKEY_CODE::KEY_KEY_N, "N"},
    {irr::EKEY_CODE::KEY_KEY_O, "O"},
    {irr::EKEY_CODE::KEY_KEY_P, "P"},
    {irr::EKEY_CODE::KEY_KEY_Q, "Q"},
    {irr::EKEY_CODE::KEY_KEY_R, "R"},
    {irr::EKEY_CODE::KEY_KEY_S, "S"},
    {irr::EKEY_CODE::KEY_KEY_T, "T"},
    {irr::EKEY_CODE::KEY_KEY_U, "U"},
    {irr::EKEY_CODE::KEY_KEY_V, "V"},
    {irr::EKEY_CODE::KEY_KEY_W, "W"},
    {irr::EKEY_CODE::KEY_KEY_X, "X"},
    {irr::EKEY_CODE::KEY_KEY_Y, "Y"},
    {irr::EKEY_CODE::KEY_KEY_Z, "Z"},
    {irr::EKEY_CODE::KEY_LWIN, "LWIN"},
    {irr::EKEY_CODE::KEY_RWIN, "RWIN"},
    {irr::EKEY_CODE::KEY_APPS, "APPS"},
    {irr::EKEY_CODE::KEY_SLEEP, "SLEEP"},
    {irr::EKEY_CODE::KEY_NUMPAD0, "NUMPAD0"},
    {irr::EKEY_CODE::KEY_NUMPAD1, "NUMPAD1"},
    {irr::EKEY_CODE::KEY_NUMPAD2, "NUMPAD2"},
    {irr::EKEY_CODE::KEY_NUMPAD3, "NUMPAD3"},
    {irr::EKEY_CODE::KEY_NUMPAD4, "NUMPAD4"},
    {irr::EKEY_CODE::KEY_NUMPAD5, "NUMPAD5"},
    {irr::EKEY_CODE::KEY_NUMPAD6, "NUMPAD6"},
    {irr::EKEY_CODE::KEY_NUMPAD7, "NUMPAD7"},
    {irr::EKEY_CODE::KEY_NUMPAD8, "NUMPAD8"},
    {irr::EKEY_CODE::KEY_NUMPAD9, "NUMPAD9"},
    {irr::EKEY_CODE::KEY_MULTIPLY, "MULTIPLY"},
    {irr::EKEY_CODE::KEY_ADD, "ADD"},
    {irr::EKEY_CODE::KEY_SEPARATOR, "SEPARATOR"},
    {irr::EKEY_CODE::KEY_SUBTRACT, "SUBTRACT"},
    {irr::EKEY_CODE::KEY_DECIMAL, "DECIMAL"},
    {irr::EKEY_CODE::KEY_DIVIDE, "DIVIDE"},
    {irr::EKEY_CODE::KEY_F1, "F1"},
    {irr::EKEY_CODE::KEY_F2, "F2"},
    {irr::EKEY_CODE::KEY_F3, "F3"},
    {irr::EKEY_CODE::KEY_F4, "F4"},
    {irr::EKEY_CODE::KEY_F5, "F5"},
    {irr::EKEY_CODE::KEY_F6, "F6"},
    {irr::EKEY_CODE::KEY_F7, "F7"},
    {irr::EKEY_CODE::KEY_F8, "F8"},
    {irr::EKEY_CODE::KEY_F9, "F9"},
    {irr::EKEY_CODE::KEY_F10, "F10"},
    {irr::EKEY_CODE::KEY_F11, "F11"},
    {irr::EKEY_CODE::KEY_F12, "F12"},
    {irr::EKEY_CODE::KEY_F13, "F13"},
    {irr::EKEY_CODE::KEY_F14, "F14"},
    {irr::EKEY_CODE::KEY_F15, "F15"},
    {irr::EKEY_CODE::KEY_F16, "F16"},
    {irr::EKEY_CODE::KEY_F17, "F17"},
    {irr::EKEY_CODE::KEY_F18, "F18"},
    {irr::EKEY_CODE::KEY_F19, "F19"},
    {irr::EKEY_CODE::KEY_F20, "F20"},
    {irr::EKEY_CODE::KEY_F21, "F21"},
    {irr::EKEY_CODE::KEY_F22, "F22"},
    {irr::EKEY_CODE::KEY_F23, "F23"},
    {irr::EKEY_CODE::KEY_F24, "F24"},
    {irr::EKEY_CODE::KEY_NUMLOCK, "NUMLOCK"},
    {irr::EKEY_CODE::KEY_SCROLL, "SCROLL"},
    {irr::EKEY_CODE::KEY_LSHIFT, "LSHIFT"},
    {irr::EKEY_CODE::KEY_RSHIFT, "RSHIFT"},
    {irr::EKEY_CODE::KEY_LCONTROL, "LCONTROL"},
    {irr::EKEY_CODE::KEY_RCONTROL, "RCONTROL"},
    {irr::EKEY_CODE::KEY_LMENU, "LMENU"},
    {irr::EKEY_CODE::KEY_RMENU, "RMENU"},
    {irr::EKEY_CODE::KEY_OEM_1, "OEM_1"},
    {irr::EKEY_CODE::KEY_PLUS, "PLUS"},
    {irr::EKEY_CODE::KEY_COMMA, "COMMA"},
    {irr::EKEY_CODE::KEY_MINUS, "MINUS"},
    {irr::EKEY_CODE::KEY_PERIOD, "PERIOD"},
    {irr::EKEY_CODE::KEY_OEM_2, "OEM_2"},
    {irr::EKEY_CODE::KEY_OEM_3, "OEM_3"},
    {irr::EKEY_CODE::KEY_OEM_4, "OEM_4"},
    {irr::EKEY_CODE::KEY_OEM_5, "OEM_5"},
    {irr::EKEY_CODE::KEY_OEM_6, "OEM_6"},
    {irr::EKEY_CODE::KEY_OEM_7, "OEM_7"},
    {irr::EKEY_CODE::KEY_OEM_8, "OEM_8"},
    {irr::EKEY_CODE::KEY_OEM_AX, "OEM_AX"},
    {irr::EKEY_CODE::KEY_OEM_102, "OEM_102"},
    {irr::EKEY_CODE::KEY_ATTN, "ATTN"},
    {irr::EKEY_CODE::KEY_CRSEL, "CRSEL"},
    {irr::EKEY_CODE::KEY_EXSEL, "EXSEL"},
    {irr::EKEY_CODE::KEY_EREOF, "EREOF"},
    {irr::EKEY_CODE::KEY_PLAY, "PLAY"},
    {irr::EKEY_CODE::KEY_ZOOM, "ZOOM"},
    {irr::EKEY_CODE::KEY_PA1, "PA1"},
    {irr::EKEY_CODE::KEY_OEM_CLEAR, "OEM_CLEAR"}};

std::map<Input::ControllerButtons, std::string> Irrlicht::controller_code_str = {
    {Input::A, "A"},
    {Input::B, "B"},
    {Input::X, "X"},
    {Input::Y, "Y"},
    {Input::LB, "LB"},
    {Input::RB, "RB"},
    {Input::SELECT, "SELECT"},
    {Input::START, "START"},
    {Input::MIDDLE, "MIDDLE"},
    {Input::LJ_PRESSED, "LJ_PRESSED"},
    {Input::RJ_PRESSED, "RJ_PRESSED"},
    {Input::LEFT_CROSS, "LEFT_CROSS"},
    {Input::RIGHT_CROSS, "RIGHT_CROSS"},
    {Input::UP_CROSS, "UP_CROSS"},
    {Input::DOWN_CROSS, "DOWN_CROSS"},
    {Input::LEFT_JOYSTICK, "LEFT_JOYSTICK"},
    {Input::RIGHT_JOYSTICK, "RIGHT_JOYSTICK"},
    {Input::RT, "RT"},
    {Input::LT, "LT"}};

Irrlicht::TextBox::~TextBox() = default;
