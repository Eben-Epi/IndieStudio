/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Exceptions.hpp
*/

#ifndef BOMBERMAN_ECS_EXCEPTIONS_HPP
#define BOMBERMAN_ECS_EXCEPTIONS_HPP


#include <exception>
#include <string>

namespace ECS
{
	class ECSException : public std::exception {
	private:
		std::string _msg;

	public:
		explicit ECSException(const std::string &msg) : _msg(msg) {};

		const char *what() const noexcept override { return this->_msg.c_str(); };
	};

	class NoSuchComponentException : public ECSException {
	public:
		explicit NoSuchComponentException(const std::string &msg) : ECSException(msg) {};
	};

	class NoSuchEntityException : public ECSException {
	public:
		explicit NoSuchEntityException(const std::string &msg) : ECSException(msg) {};
	};

	class NoSuchSystemException : public ECSException {
	public:
		explicit NoSuchSystemException(const std::string &msg) : ECSException(msg) {};
	};

	class MissingDependenciesException : public ECSException {
	public:
		explicit MissingDependenciesException(const std::string &msg) : ECSException(msg) {};
	};

	class InvalidStateException : public ECSException {
	public:
		explicit InvalidStateException(const std::string &msg) : ECSException(msg) {};
	};

	class InvalidNameException : public ECSException {
	public:
		explicit InvalidNameException(const std::string &msg) : ECSException(msg) {};
	};

	class InvalidSerializedStringException : public ECSException {
	public:
		explicit InvalidSerializedStringException(const std::string &msg) : ECSException(msg) {};
	};
}

#endif //BOMBERMAN_EXCEPTIONS_HPP
