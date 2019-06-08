/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Exception.hpp
*/

#ifndef BOMBERMAN_EXCEPTION_HPP
#define BOMBERMAN_EXCEPTION_HPP

#include <exception>
#include <stdexcept>
#include <string>

namespace Sound
{
	class SoundException : public std::exception {
	private:
		std::string _msg;

	public:
		explicit SoundException(const std::string &msg) : _msg(msg) {};

		const char *what() const noexcept override { return this->_msg.c_str(); };
	};

	class InvalidFileException : public SoundException {
	public:
		explicit InvalidFileException(const std::string &msg) : SoundException(msg) {};
	};

	class InvalidSoundIdentifierException : public SoundException {
	public:
		explicit InvalidSoundIdentifierException(const std::string &msg) : SoundException(msg) {};
	};

	class AlreadyLoadedException : public SoundException {
	public:
		explicit AlreadyLoadedException(const std::string &msg) : SoundException(msg) {};
	};
}

#endif //BOMBERMAN_EXCEPTION_HPP
