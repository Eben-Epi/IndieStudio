/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** TextBox.hpp
*/

#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP

#include "../../ecs/data/Vector2.hpp"
#include <irrlicht/irrlicht.h>
#include <string>
#include <irrlicht/IGUIEnvironment.h>

namespace Irrlicht
{
	class TextBox {
	public:
		TextBox(ECS::Point pos, ECS::Vector4<int> size, unsigned id, irr::gui::IGUIEnvironment *guienv, std::string text = "",\
			bool border = false, bool worlWrap = false, bool fillBackground = false);
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

		unsigned id;
	private:
		std::string _text;
		ECS::Point _pos;
		ECS::Vector4<int> _size;
		irr::gui::IGUIEnvironment* _guienv;
		irr::gui::IGUIStaticText *_textBox;
		bool _visible;
		bool _border;
		bool _worldWrap;
		bool _fillbackground;
	};
} // namespace Irrlicht

#endif