/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** Button.cpp
*/

#include <iostream>
#include "Button.hpp"
#include "../../../ecs/data/Vector2.hpp"

Irrlicht::Button::Button(ECS::Point pos, ECS::Vector4<int> size, unsigned id, irr::gui::IGUIEnvironment *guienv, std::string text) :
    id(id),
    _pos({0, 0}),
    _size(size),
    _guienv(guienv),
    _visible(true)
{
    wchar_t *val = reinterpret_cast<wchar_t *>(malloc(sizeof(*val) * (text.size() + 1)));

    for (size_t i = 0; i < text.size(); i++)
        val[i] = text[i];
    val[text.size()] = 0;
    if (!text.empty()) {
        this->_text = text;
        this->_button = this->_guienv->addButton(irr::core::rect<irr::s32>(_size.a, _size.b, _size.c, _size.d), 0, this->id, val);
        this->setPos(pos);
        return;
    }
    free(val);
    this->_button = this->_guienv->addButton(irr::core::rect<irr::s32>(_size.a, _size.b, _size.c, _size.d), 0, this->id);
    this->setPos(pos);
}

const std::string &Irrlicht::Button::getText() {
    return this->_text;
}

const ECS::Point &Irrlicht::Button::getPos() {
    return this->_pos;
}

const ECS::Vector4<int> &Irrlicht::Button::getSize() {
    return this->_size;
}

void Irrlicht::Button::setText(std::string text) {
    this->_button->remove();
    wchar_t *val = reinterpret_cast<wchar_t *>(malloc(sizeof(*val) * (text.size() + 1)));

    for (size_t i = 0; i < text.size(); i++)
        val[i] = text[i];
    val[text.size()] = 0;
    if (!text.empty()) {
        this->_text = text;
        this->_button = this->_guienv->addButton(
                irr::core::rect<irr::s32>(_size.a, _size.b, _size.c, _size.d), 0, this->id, val);
    } else
        this->_button = this->_guienv->addButton(irr::core::rect<irr::s32>(_size.a, _size.b, _size.c, _size.d), 0,
                                                 this->id);
    free(val);
    setPos(this->_pos);
}

void Irrlicht::Button::setPos(ECS::Point pos) {
        this->_pos = pos;
        this->_button->setRelativePosition(irr::core::position2di((int)_pos.x, (int)_pos.y));
}

void Irrlicht::Button::setSize(ECS::Vector4<int> size) {
    this->_button->remove();
    if (size.a != _size.a && size.b != _size.b && size.c != _size.c && size.d && _size.d) {
        this->_size = size;
        this->_button = this->_guienv->addButton(
                irr::core::rect<irr::s32>(_size.a, _size.b, _size.c, _size.d), 0, this->id,
                reinterpret_cast<const wchar_t *>(&this->_text));
        setPos(this->_pos);
        return;
    }
}

bool Irrlicht::Button::isPressed() {
    return this->_button->isPressed();
}

void Irrlicht::Button::setVisible(bool visible)
{
	if (this->_visible == visible)
		return;
	this->_visible = visible;
	this->_button->setVisible(visible);
}

Irrlicht::Button::~Button() = default;
