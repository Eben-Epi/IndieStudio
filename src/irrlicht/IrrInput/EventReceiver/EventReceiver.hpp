/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** EventReceiver.hpp
*/

#ifndef BOMBERMAN_EVENTRECEIVER_HPP
#define BOMBERMAN_EVENTRECEIVER_HPP

#include <irrlicht/irrlicht.h>
#include <vector>

namespace Irrlicht {
    class EventReceiver : public irr::IEventReceiver
    {
    public:
        EventReceiver();
        ~EventReceiver() = default;

        //MEMBER FUNCTIONS
        void update();
        virtual void onEvent(const irr::SEvent &event);
        virtual bool isKeyPressed(const irr::EKEY_CODE keyCode) const;

    private:
        //PROPERTIES
        std::vector<bool> _keys;
        };
}


#endif //BOMBERMAN_EVENTRECEIVER_HPP
