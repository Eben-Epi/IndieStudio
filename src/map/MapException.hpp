/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MapException.cpp
*/

#ifndef BOMBERMAN_MAPEXCEPTION_HPP
#define BOMBERMAN_MAPEXCEPTION_HPP

namespace Map {
    class MapException : public std::exception {
    private:
        std::string _msg;

    public:
        explicit MapException(const std::string &msg) : _msg(msg) {};

        const char *what() const noexcept override { return this->_msg.c_str(); };
    };

    class MapTooSmallException : public MapException {
    public:
        explicit MapTooSmallException(const std::string &msg) : MapException(msg) {};
    };

}


#endif //BOMBERMAN_MAPEXCEPTION_HPP
