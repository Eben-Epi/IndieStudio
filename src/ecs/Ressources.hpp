/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Ressources.hpp
*/

#ifndef BOMBERMAN_RESSOURCES_HPP
#define BOMBERMAN_RESSOURCES_HPP


#include "../Input/Input.hpp"
#include "../irrlicht/GameScene/GameScene.hpp"

namespace ECS
{
	struct Ressources {
		Irrlicht::GameScene                        &gameScene;
		std::vector<std::unique_ptr<Input::Input>> &inputs;
	};
}


#endif //BOMBERMAN_RESSOURCES_HPP
