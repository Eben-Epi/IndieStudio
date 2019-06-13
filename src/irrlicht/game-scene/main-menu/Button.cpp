/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** Button.cpp
*/

#include "Button.hpp"

Irrlicht::Button::Button(ECS::Point pos, ECS::Vector2<unsigned int> size, unsigned id, std::string text) :
    id(id),
    _pos(pos),
    _size(size)
{
    if (!text.empty()) {
        this->_text = text;
        this->_button = this->_guienv->addButton(irr::core::rect<irr::s32>((int)_pos.x, (int)_pos.y, _size.x, _size.y), 0, this->id, reinterpret_cast<const wchar_t *>(&this->_text));
    }
    this->_button = this->_guienv->addButton(irr::core::rect<irr::s32>((int)_pos.x, (int)_pos.y, _size.x, _size.y), 0, this->id);
}

const std::string &Irrlicht::Button::getText() {
    return this->_text;
}

const ECS::Point &Irrlicht::Button::getPos() {
    return this->_pos;
}

const ECS::Vector2<unsigned> &Irrlicht::Button::getSize() {
    return this->_size;
}

void Irrlicht::Button::setText(std::string text) {
    delete this->_button;
    this->_text = text;
    if (!text.empty())
        this->_button = this->_guienv->addButton(irr::core::rect<irr::s32>((int)_pos.x, (int)_pos.y, _size.x, _size.y), 0, this->id, reinterpret_cast<const wchar_t *>(&this->_text));
    this->_button = this->_guienv->addButton(irr::core::rect<irr::s32>((int)_pos.x, (int)_pos.y, _size.x, _size.y), 0, this->id);
}

void Irrlicht::Button::setPos(ECS::Point pos) {
    if (pos.x != _pos.x && pos.y != pos.y) {
        this->_pos = pos;
        this->_button->setRelativePosition(irr::core::position2di((int)pos.x, (int)pos.y));
    }
}

void Irrlicht::Button::setSize(ECS::Vector2<unsigned> size) {
    delete this->_button;
    if (size.x != _size.x && size.y != _size.y) {
        this->_size = size;
        this->_button = this->_guienv->addButton(
                irr::core::rect<irr::s32>((int) _pos.x, (int) _pos.y, _size.x, _size.y), 0, this->id,
                reinterpret_cast<const wchar_t *>(&this->_text));
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
