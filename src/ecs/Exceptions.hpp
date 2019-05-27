/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Exceptions.hpp
*/

#ifndef BOMBERMAN_EXCEPTIONS_HPP
#define BOMBERMAN_EXCEPTIONS_HPP


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
}

#endif //BOMBERMAN_EXCEPTIONS_HPP
