/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** TextBox.cpp
*/

#include <iostream>
#include "TextBox.hpp"
#include "keys_to_str.hpp"

Irrlicht::TextBox::TextBox(ECS::Point pos, ECS::Vector4<int> size, unsigned id, irr::gui::IGUIEnvironment *guienv, std::string text, \
bool border, bool worlWrap, bool fillBackground) :
    id(id),
    _pos({0, 0}),
    _size(size),
    _guienv(guienv),
    _visible(true),
    _border(border),
    _worldWrap(worlWrap),
    _fillbackground(fillBackground)
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
        this->setPos(pos);
        return;
    }
    free(val);
    this->_textBox = this->_guienv->addStaticText(\
        reinterpret_cast<const wchar_t *>(&this->_text), irr::core::rect<irr::s32>(_size.a, _size.b, _size.c, _size.d), \
        this->_border, this->_worldWrap, 0, this->id, this->_fillbackground);
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
    delete this->_textBox;
    this->_text = text;
    if (!text.empty()) {
        this->_textBox = this->_guienv->addStaticText(\
            reinterpret_cast<const wchar_t *>(&this->_text), irr::core::rect<irr::s32>(_size.a, _size.b, _size.c, _size.d), \
            this->_border, this->_worldWrap, 0, this->id, this->_fillbackground);
        setPos(this->_pos);
        return;
    }
    this->_textBox = this->_guienv->addStaticText(
        reinterpret_cast<const wchar_t *>(&this->_text), irr::core::rect<irr::s32>(_size.a, _size.b, _size.c, _size.d),
        this->_border, this->_worldWrap, 0, this->id, this->_fillbackground);
    setPos(this->_pos);
}

void Irrlicht::TextBox::setPos(ECS::Point pos)
{

    if (pos.x != _pos.x && pos.y != _pos.y) {
        this->_pos = pos;
        this->_textBox->setRelativePosition(irr::core::position2di((int)_pos.x, (int)_pos.y));
    }
}

void Irrlicht::TextBox::setSize(ECS::Vector4<int> size)
{
    delete this->_textBox;
    if (size.a != _size.a && size.b != _size.b && size.c != _size.c && size.d && _size.d) {
        this->_size = size;
        this->_textBox = this->_guienv->addStaticText(
            reinterpret_cast<const wchar_t *>(&this->_text), irr::core::rect<irr::s32>(_size.a, _size.b, _size.c, _size.d),
            this->_border, this->_worldWrap, 0, this->id, this->_fillbackground);
        setPos(this->_pos);
        return;
    }
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
    this->_textBox->setTextAlignment(horizontal, vertical);
}

void Irrlicht::TextBox::setColorOfText(irr::video::SColor color)
{
    this->_textBox->setOverrideColor(color);
}

void Irrlicht::TextBox::setTextFromIrrlichtKeysEnum(unsigned key, bool mode)
{
    delete this->_textBox;
    if (mode)
        this->_text = Irrlicht::ekey_code_str.at(key);
    else
        this->_text = Irrlicht::controller_code_str.at(key);

    this->_textBox = this->_guienv->addStaticText(
        reinterpret_cast<const wchar_t *>(&this->_text), irr::core::rect<irr::s32>(_size.a, _size.b, _size.c, _size.d),
        this->_border, this->_worldWrap, 0, this->id, this->_fillbackground);
    setPos(this->_pos);
}

Irrlicht::TextBox::~TextBox() = default;
