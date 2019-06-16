//
// Created by eben_epitech on 6/10/19.
//

#ifndef BOMBERMAN_EXCEPTIONS_HPP
#define BOMBERMAN_EXCEPTIONS_HPP


#include <exception>
#include <string>

namespace Irrlicht
{
    class IrrlichtException : std::exception {
    private:
        std::string _msg;

    public:
        IrrlichtException(const std::string &msg) : _msg(msg) {};
        const char *what() const noexcept override { return this->_msg.c_str(); };
    };

    class NoSuchEntityException : public IrrlichtException {
    public:
        NoSuchEntityException(const std::string &msg) : IrrlichtException(msg) {};
    };

    class NoSuchSceneException : public IrrlichtException {
    public:
        NoSuchSceneException(const std::string &msg) : IrrlichtException(msg) {};
    };
}


#endif //BOMBERMAN_EXCEPTIONS_HPP
