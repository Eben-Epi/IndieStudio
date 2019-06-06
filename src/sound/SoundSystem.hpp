/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** SoundSystem.hpp
*/

#ifndef BOMBERMAN_SOUNDSYSTEM_HPP
#define BOMBERMAN_SOUNDSYSTEM_HPP


#include <string>
#include <map>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

namespace Sound
{
	enum SoundState {
		Playing,
		Paused,
		Stopped
	};

	class SoundSystem {
	public:
		SoundSystem() = default;
		void loadSound(const std::string &name);
		void destroySound(const std::string &id);
		void playSound(const std::string &id);
		void pauseSound(const std::string &id);
		void stopSound(const std::string &id);
		void setLoop(const std::string &id, bool loop = true);
		bool isLooping(const std::string &id);

	private:
		struct Sound {
			sf::Sound sound;
			sf::SoundBuffer buffer;
		};

		std::map<std::string, Sound> _loadedSounds;
	};
}


#endif //BOMBERMAN_SOUNDSYSTEM_HPP
