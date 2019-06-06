//
// Created by Eben on 27/05/2019.
//

#ifndef BOMBERMAN_SCREEN_HPP
#define BOMBERMAN_SCREEN_HPP

#include <string>
#include "../Animations.hpp"
#include "irrlicht/irrlicht.h"
#include "../../ecs/Entity.hpp"
#include "../../ecs/data/Vector2.hpp"


//#define TRANSFORM_COLOR_TO_SFML_COLOR(color) sf::Color(static_cast<sf::Uint8>(color >> 16), static_cast<sf::Uint8>(color >> 8), static_cast<sf::Uint8>(color))
#define WINDOW_NAME "Bomberman"

namespace Irrlicht
{
    class GameScene;

    class Screen {
    public:
        explicit Screen(int width = 640, int height = 480, int colorDepth = 32, bool fullscreen = false, bool vsync = true);
        ~Screen() = default;

        //MEMBER FUNCTIONS
        bool display();
        bool setFullscreen(bool fullscreen);
        bool setVsync(bool vsync);
        bool setWindowSize(int width, int height);


    private:
        irr::video::E_DRIVER_TYPE _driverType; // TODO differenciate OpenGL and Dx9 when running under win32/64 or GNU/UNIX
        int _width;
        int _height;
        int _colorDepth;
        bool _fullscreen;
        bool _vsync;
        std::vector<GameScene *> scenes;

        //PROPERTIES
        irr::IrrlichtDevice* _device;
        irr::video::IVideoDriver* _driver;
        //unsigned _lastId;

        //void drawRect(ECS::Point pos, ECS::Vector2<unsigned> size, Color color = 0xFFFFFF, bool filled = false);

    };
}


#endif //BOMBERMAN_IRRLICHT_HPP
