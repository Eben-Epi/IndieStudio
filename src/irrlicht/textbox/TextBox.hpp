/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** TextBox.hpp
*/

#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP

#include <irrlicht/irrlicht.h>
#include <string>
#include <map>
#include <irrlicht/IGUIEnvironment.h>
#include "../../ecs/data/Vector2.hpp"
#include "../../input/Controller.hpp"

namespace Irrlicht
{
	extern std::map<Input::ControllerButtons, std::string> controller_code_str;
	extern std::map<irr::EKEY_CODE, std::string> ekey_code_str;

	class TextBox
	{
	public:
		TextBox(ECS::Point pos, ECS::Vector4<int> size, unsigned id, irr::gui::IGUIEnvironment *guienv, std::string text = "",
				bool border = false, bool worlWrap = false, bool fillBackground = false,
				irr::gui::EGUI_ALIGNMENT horizontal = irr::gui::EGUIA_CENTER, irr::gui::EGUI_ALIGNMENT vertical = irr::gui::EGUIA_CENTER);
		~TextBox();

		const std::string &getText();
		const ECS::Point &getPos();
		const ECS::Vector4<int> &getSize();
		void setText(std::string text);
		void setPos(ECS::Point pos);
		void setSize(ECS::Vector4<int> size);
		void setVisible(bool visible);
		void setBackgroundColor(irr::video::SColor color);
		void setDrawBackground(bool draw);
		void setDrawBorder(bool draw);
		void setTextAlignment(irr::gui::EGUI_ALIGNMENT horizontal, irr::gui::EGUI_ALIGNMENT vertical);
		void setColorOfText(irr::video::SColor color);

		unsigned id;

	private:
		std::string _text;
		ECS::Point _pos;
		ECS::Vector4<int> _size;
		irr::gui::IGUIEnvironment *_guienv;
		irr::gui::IGUIStaticText *_textBox;
		bool _visible;
		bool _border;
		bool _worldWrap;
		bool _fillbackground;
		irr::gui::EGUI_ALIGNMENT _vertical;
		irr::gui::EGUI_ALIGNMENT _horizontal;
		irr::video::SColor _color;
		irr::video::SColor _backgroundColor;
	};
} // namespace Irrlicht

#endif