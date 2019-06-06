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
	void SoundSystem::loadSound(const std::string &name)
	{
		try {
			this->_loadedSounds.at(name);
			throw AlreadyLoadedException(name + " has already been loaded");
		} catch (std::out_of_range &) {
			Sound &sound = this->_loadedSounds[name];

			if (!sound.buffer.loadFromFile("media/sounds/" + name + ".ogg"))
				throw InvalidFileException("Cannot load sound file media/sounds/" + name + ".ogg");
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
}