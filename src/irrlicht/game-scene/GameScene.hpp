//
// Created by Eben on 05/06/2019.
//

#ifndef INDIE_GAMESCENE_HPP
#define INDIE_GAMESCENE_HPP

#include <string>
#include <irrlicht/Keycodes.h>
#include <irrlicht/IEventReceiver.h>
#include <irrlicht/IVideoDriver.h>
#include <irrlicht/irrlicht.h>
#include <iostream>
#include "../../ecs/Entity.hpp"
#include "../../ecs/data/Vector2.hpp"
#include "irr-entity/IrrEntity.hpp"
#include "../irr-input/event-receiver/EventReceiver.hpp"
#include "hud/Button.hpp"
#include "../textbox/TextBox.hpp"

namespace Irrlicht {

	class Screen;
	class MainMenu;

	enum ControllerAxisGS {
		LEFT_JOYSTICK_UP = 0,
		LEFT_JOYSTICK_DOWN,
		LEFT_JOYSTICK_LEFT,
		LEFT_JOYSTICK_RIGHT,
		RIGHT_JOYSTICK_UP,
		RIGHT_JOYSTICK_DOWN,
		RIGHT_JOYSTICK_LEFT,
		RIGHT_JOYSTICK_RIGHT,
		RT,
		LT,
		NUMBER_AXIS
	};

	class GameScene {
	public:
		GameScene(Screen &screen, std::string name, unsigned id);
		virtual ~GameScene() = default;

		unsigned int registerEntity(const std::string &name);
		void deleteEntity(unsigned id);
		bool areColliding(unsigned entity1, unsigned entity2);
		void setAnimation(unsigned entity, Animations anim);
		void setPosition(unsigned entity, float x, float y);
		void setRotation(unsigned entity, float y);
		void setScale(unsigned entity, float x, float y);
		void setSize(unsigned entity, float x, float y);
		void addCamera(float posX, float posY, float posZ, float lookAtX, float lookAtY, float lookAtZ);
		ECS::Vector2<float> getSize(unsigned entity);
		bool isKeyPressed(irr::EKEY_CODE key);
		bool isJoystickButtonPressed(unsigned joystickId, unsigned button);
		bool isGuiButtonPressed(unsigned id);
		float getJoystickAxisPosition(unsigned joystickId, unsigned axis);
		bool isJoystickAxisPressed(unsigned joystickId, ControllerAxisGS axis, unsigned threshold = 16384);
		void changeCurrentGameScene(std::string sceneName);
		virtual bool update();

		const std::string sceneName;
		const unsigned id;
	protected:
		IrrEntity &_getEntity(unsigned entity_id);
		std::vector<std::unique_ptr<IrrEntity>> _entities;
		std::vector<std::unique_ptr<Button>> _buttons;
		std::vector<std::unique_ptr<TextBox>> _textBoxes;
		unsigned _entitiesId;
		Screen &_window;
		EventReceiver &_eventReceiver;
	};
}


#endif //INDIE_GAMESCENE_HPP
