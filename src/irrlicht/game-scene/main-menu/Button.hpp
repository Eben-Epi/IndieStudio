/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** Button.hpp
*/

#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "../../../ecs/data/Vector2.hpp"
#include <irrlicht/irrlicht.h>
#include <string>
#include <irrlicht/IGUIEnvironment.h>

namespace Irrlicht
{
	class Button {
		Button(ECS::Point pos, ECS::Vector2<unsigned> size, unsigned id, std::string text = "");
		~Button();

		const std::string &getText();
		const ECS::Point &getPos();
		const ECS::Vector2<unsigned> &getSize();
		void setText(std::string text);
		void setPos(ECS::Point pos);
		void setSize(ECS::Vector2<unsigned> size);
		bool isPressed();

		unsigned id;
	private:
	    std::string _text;
		ECS::Point _pos;
		ECS::Vector2<unsigned> _size;
        irr::gui::IGUIEnvironment* _guienv;
        irr::gui::IGUIButton* _button;
	};
} // namespace Irrlicht

#endif