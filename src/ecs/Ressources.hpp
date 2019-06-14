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
	class ECSCore;

	struct Ressources {
		Irrlicht::GameScene         &gameScene;
		Sound::SoundSystem          &soundSystem;
		ECSCore	                    &core;
		std::vector<Input::Input *> inputs;
		Vector2<unsigned>           mapSize = {0, 0};

		Ressources(Irrlicht::GameScene &scene, Sound::SoundSystem &soundSystem, ECSCore &core, std::vector<Input::Input *> &&inputs = {}) :
			gameScene(scene),
			soundSystem(soundSystem),
			core(core),
			inputs(inputs)
		{}
	};
}


#endif //BOMBERMAN_RESSOURCES_HPP
