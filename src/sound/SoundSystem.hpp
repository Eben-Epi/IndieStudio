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
	class SoundSystem {
	public:
		SoundSystem() = default;
		~SoundSystem();
		void loadSound(const std::string &id);
		void playSoundOverBackgroundMusic(const std::string &id, float volume = 100);
		unsigned playSound(const std::string &id, float volume = 100);
		void pauseBackgroundMusic();
		void pause(unsigned id);
		void resumeBackgroundMusic();
		void resume(unsigned id);
		void stopBackgroundMusic();
		void stop(unsigned id);
		void setBackgroundMusic(const std::string &id, float volume = 100);

	private:
		std::thread                            _bgThread;
		std::unique_ptr<unsigned>              _backgroundMusic;
		std::map<std::string, sf::SoundBuffer> _loadedSounds;
		std::vector<std::unique_ptr<sf::Sound>>_sounds;
	};
}


#endif //BOMBERMAN_SOUNDSYSTEM_HPP
