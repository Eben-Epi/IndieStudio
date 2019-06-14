/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Ressources.hpp
*/

#ifndef BOMBERMAN_RESSOURCES_HPP
#define BOMBERMAN_RESSOURCES_HPP


#include "../input/Input.hpp"
#include "../irrlicht/game-scene/GameScene.hpp"
#include "../sound/SoundSystem.hpp"

namespace ECS
{
	struct Ressources {
		Irrlicht::GameScene                        &gameScene;
		std::vector<std::unique_ptr<Input::Input>> &inputs;
		Sound::SoundSystem                         soundSystem{};
		Vector2<unsigned>                          mapSize = {0, 0};

		Ressources(Irrlicht::GameScene &scene, std::vector<std::unique_ptr<Input::Input>> &inputs) :
			gameScene(scene),
			inputs(inputs)
		{}
	};
}


#endif //BOMBERMAN_RESSOURCES_HPP
