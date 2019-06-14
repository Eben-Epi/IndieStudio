/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** SoundSystem.cpp
*/

#include "SoundSystem.hpp"
#include "Exception.hpp"

namespace Sound
{
	SoundSystem::~SoundSystem()
	{
		this->_backgroundMusic.reset(nullptr);
		for (auto &sound : this->_sounds)
			sound->stop();
		if (this->_bgThread.joinable())
			this->_bgThread.join();
	}

	void SoundSystem::loadSound(const std::string &id)
	{
        try {
            this->_loadedSounds.at(id);
            throw AlreadyLoadedException(id + " has already been loaded");
        } catch (std::out_of_range &) {
#if defined(_WIN32) && !defined(__GNUC__)
            this->_loadedSounds[id];
#else
            if (!this->_loadedSounds[id].loadFromFile("media/sounds/" + id + ".ogg"))
                throw InvalidFileException("Cannot load sound file media/sounds/" + id + ".ogg");
#endif
        }
	}

	unsigned SoundSystem::playSound(const std::string &id, float volume)
	{
		try {
			for (unsigned i = 0; i < this->_sounds.size(); i++) {
				auto &sound = this->_sounds[i];

				if (sound->getStatus() == sf::Sound::Stopped) {
					sound->setBuffer(this->_loadedSounds.at(id));
					sound->setVolume(volume);
					sound->setLoop(false);
					sound->play();
					return i;
				}
			}
			this->_sounds.emplace_back(new sf::Sound());
			sf::Sound &sound = *this->_sounds.back();

			sound.setBuffer(this->_loadedSounds.at(id));
			sound.setVolume(volume);
			sound.play();
			return this->_sounds.size() - 1;
		} catch (std::out_of_range &) {
			throw InvalidSoundIdentifierException("No sound loaded has id " + id);
		}
	}


	void SoundSystem::playSoundOverBackgroundMusic(const std::string &id, float volume)
	{
		int i = this->playSound(id);
		if (this->_backgroundMusic) {
			this->_sounds[*this->_backgroundMusic]->pause();
			if (this->_bgThread.joinable())
				this->_bgThread.detach();
			this->_bgThread = std::thread{[this, i, volume]() {
				while (this->_sounds[i]->getStatus() == sf::Sound::Playing)
					std::this_thread::sleep_for(std::chrono::milliseconds(100));
				if (this->_backgroundMusic) {
					this->_sounds[*this->_backgroundMusic]->setVolume(volume);
					this->_sounds[*this->_backgroundMusic]->play();
				}
			}};
		}
	}

	void SoundSystem::setBackgroundMusic(const std::string &id, float volume)
	{
		this->_backgroundMusic.reset(new unsigned(this->playSound(id, volume)));
		this->_sounds[*this->_backgroundMusic]->setLoop(true);
	}

	void SoundSystem::pause(unsigned id)
	{
		try {
			this->_sounds[id]->pause();
		} catch (std::out_of_range &) {
			throw InvalidSoundIdentifierException("No sound loaded has id " + std::to_string(id));
		}
	}

	void SoundSystem::stop(unsigned id)
	{
		try {
			this->_sounds[id]->stop();
		} catch (std::out_of_range &) {
			throw InvalidSoundIdentifierException("No sound loaded has id " + std::to_string(id));
		}
	}

	void SoundSystem::resume(unsigned id)
	{
		try {
			this->_sounds[id]->play();
		} catch (std::out_of_range &) {
			throw InvalidSoundIdentifierException("No sound loaded has id " + std::to_string(id));
		}
	}

	void SoundSystem::pauseBackgroundMusic()
	{
		if (!this->_backgroundMusic)
			throw InvalidSoundIdentifierException("No background music is playing");
		this->pause(*this->_backgroundMusic);
	}

	void SoundSystem::stopBackgroundMusic()
	{
		if (!this->_backgroundMusic)
			throw InvalidSoundIdentifierException("No background music is playing");
		this->stop(*this->_backgroundMusic);
	}

	void SoundSystem::resumeBackgroundMusic()
	{
		if (!this->_backgroundMusic)
			throw InvalidSoundIdentifierException("No background music is playing");
		this->resume(*this->_backgroundMusic);
	}
}