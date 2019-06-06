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
		this->_background.reset(nullptr);
		for (auto &sound : this->_loadedSounds)
			sound.second.sound.stop();
		if (this->_bgThread.joinable())
			this->_bgThread.join();
	}

	void SoundSystem::loadSound(const std::string &id)
	{
		try {
			this->_loadedSounds.at(id);
			throw AlreadyLoadedException(id + " has already been loaded");
		} catch (std::out_of_range &) {
			Sound &sound = this->_loadedSounds[id];

			if (!sound.buffer.loadFromFile("media/sounds/" + id + ".ogg"))
				throw InvalidFileException("Cannot load sound file media/sounds/" + id + ".ogg");
			sound.sound.setBuffer(sound.buffer);
		}
	}

	void SoundSystem::destroySound(const std::string &id)
	{
		try {
			this->_loadedSounds.at(id);
			this->_loadedSounds.erase(id);
		} catch (std::out_of_range &) {
			throw InvalidSoundIdentifierException("No sound loaded has id " + id);
		}
	}

	bool SoundSystem::isLooping(const std::string &id)
	{
		try {
			return this->_loadedSounds.at(id).sound.getLoop();
		} catch (std::out_of_range &) {
			throw InvalidSoundIdentifierException("No sound loaded has id " + id);
		}
	}

	void SoundSystem::pauseSound(const std::string &id)
	{
		try {
			this->_loadedSounds.at(id).sound.pause();
		} catch (std::out_of_range &) {
			throw InvalidSoundIdentifierException("No sound loaded has id " + id);
		}
	}

	void SoundSystem::playSound(const std::string &id)
	{
		try {
			this->_loadedSounds.at(id).sound.play();
		} catch (std::out_of_range &) {
			throw InvalidSoundIdentifierException("No sound loaded has id " + id);
		}
	}

	void SoundSystem::setLoop(const std::string &id, bool loop)
	{
		try {
			this->_loadedSounds.at(id).sound.setLoop(loop);
		} catch (std::out_of_range &) {
			throw InvalidSoundIdentifierException("No sound loaded has id " + id);
		}
	}

	void SoundSystem::stopSound(const std::string &id)
	{
		try {
			this->_loadedSounds.at(id).sound.pause();
		} catch (std::out_of_range &) {
			throw InvalidSoundIdentifierException("No sound loaded has id " + id);
		}
	}

	void SoundSystem::playSoundOverBackgroundMusic(const std::string &id)
	{
		this->playSound(id);
		if (this->_background) {
			this->pauseSound(*this->_background);
			this->_bgThread = std::thread{[this, id]() {
				while (this->getState(id) == Playing)
					std::this_thread::sleep_for(std::chrono::milliseconds(100));
				if (this->_background)
					this->playSound(*this->_background);
			}};
		}
	}

	void SoundSystem::setBackgroundMusic(const std::string &id)
	{
		if (this->_background)
			this->stopSound(*this->_background);
		this->_background.reset(new std::string(id));
	}

	SoundState SoundSystem::getState(const std::string &id)
	{
		try {
			switch (this->_loadedSounds.at(id).sound.getStatus()) {
				case sf::Sound::Stopped:
					return ::Sound::Stopped;
				case sf::Sound::Playing:
					return ::Sound::Playing;
				case sf::Sound::Paused:
					return ::Sound::Paused;
			}
		} catch (std::out_of_range &) {
			throw InvalidSoundIdentifierException("No sound loaded has id " + id);
		}
		return ::Sound::Paused;
	}

	void SoundSystem::setVolume(const std::string &id, float volume)
	{
		try {
			this->_loadedSounds.at(id).sound.setVolume(volume);
		} catch (std::out_of_range &) {
			throw InvalidSoundIdentifierException("No sound loaded has id " + id);
		}
	}
}