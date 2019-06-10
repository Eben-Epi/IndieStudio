/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Ressources.hpp
*/

#ifndef BOMBERMAN_RESSOURCES_HPP
#define BOMBERMAN_RESSOURCES_HPP


#include "../input/Input.hpp"
#include "../irrlicht/GameScene/GameScene.hpp"
#include "../sound/SoundSystem.hpp"

namespace ECS
{
	struct Ressources {
		Irrlicht::GameScene                        &gameScene;
		std::vector<std::unique_ptr<Input::Input>> &inputs;
		Sound::SoundSystem                         soundSystem;
	};
}


#endif //BOMBERMAN_RESSOURCES_HPP
