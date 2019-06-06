/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** SoundSystem.hpp
*/

#ifndef BOMBERMAN_SOUNDSYSTEM_HPP
#define BOMBERMAN_SOUNDSYSTEM_HPP


#include <map>
#include <memory>
#include <string>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <thread>

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
		~SoundSystem();
		void loadSound(const std::string &id);
		void destroySound(const std::string &id);
		void playSound(const std::string &id);
		void pauseSound(const std::string &id);
		void stopSound(const std::string &id);
		SoundState getState(const std::string &id);
		bool isLooping(const std::string &id);
		void setBackgroundMusic(const std::string &id);
		void setLoop(const std::string &id, bool loop = true);
		void playSoundOverBackgroundMusic(const std::string &id);

	private:
		struct Sound {
			sf::Sound sound;
			sf::SoundBuffer buffer;
		};

		std::thread                  _bgThread;
		std::unique_ptr<std::string> _background;
		std::map<std::string, Sound> _loadedSounds;
	};
}


#endif //BOMBERMAN_SOUNDSYSTEM_HPP
