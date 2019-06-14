/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** KeyManagingMenu.hpp
*/

#ifndef KEY_MANAGING_MENU_HPP
#define KEY_MANAGING_MENU_HPP

#include <vector>
#include <memory>
#include "../GameScene.hpp"
#include "../main-menu/Button.hpp"

namespace Irrlicht
{
	enum KeysButtonName
	{
		BACKBACK = 0,
		P1_UP,
		P1_DOWN,
		P1_LEFT,
		P1_RIGHT,
		P1_DROP,
		P1_ULT,
		P2_UP,
		P2_DOWN,
		P2_LEFT,
		P2_RIGHT,
		P2_DROP,
		P2_ULT,
		P3_UP,
		P3_DOWN,
		P3_LEFT,
		P3_RIGHT,
		P3_DROP,
		P3_ULT,
		P4_UP,
		P4_DOWN,
		P4_LEFT,
		P4_RIGHT,
		P4_DROP,
		P4_ULT,
	};

	class KeyManagingMenu : public GameScene
	{
	public:
		KeyManagingMenu(Screen &screen, const std::string &name, unsigned id /*, très probablement l'input */);
		~KeyManagingMenu() = default;
		void changeCurrentGameScene(std::string sceneName);
		bool update() override;

	private:
		//PROPERTIES
		std::vector<std::unique_ptr<Button>> _buttons;
		//ajouter très probablement l'input
		};
}

#endif