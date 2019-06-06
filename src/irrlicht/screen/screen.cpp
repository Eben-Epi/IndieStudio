//
// Created by Eben on 27/05/2019.
//

#include <iostream>
#include <irrlicht/irrlicht.h>


#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

#include "Screen.hpp"

Irrlicht::Screen::Screen(int width, int height, int colorDepth, bool fullscreen, bool vsync) : _width(width), _height(height), _colorDepth(colorDepth), _fullscreen(fullscreen), _vsync(vsync) { //TODO FULLSCREEN, SET WINDOW SIZE AND TYPE, ENABLE VSYNC
    this->_driverType = irr::video::EDT_OPENGL;
    this->_device = irr::createDevice(_driverType, irr::core::dimension2d<irr::u32>(_width, _height), _colorDepth,
                                 _fullscreen, false, _vsync, nullptr);
    this->_driver = _device->getVideoDriver();
    this->_device->setResizable(true);
}


void Irrlicht::Screen::display(irr::scene::ISceneManager *smgr, irr::gui::IGUIEnvironment *guienv) { //TODO COLOR SCENE
    int lastFPS = -1;
    if (this->_device->isWindowActive())
    {
        this->_driver->beginScene(true, true, irr::video::SColor(255,200,200,200));
        if (smgr != nullptr)
            smgr->drawAll();
        if (guienv != nullptr)
            guienv->drawAll();
        this->_driver->endScene();

        int fps = this->_driver->getFPS();

        if (lastFPS != fps)
        {
            irr::core::stringw str = "Indie Studio [";
            str += this->_driver->getName();
            str += "] FPS:";
            str += fps;

            this->_device->setWindowCaption(str.c_str());
            lastFPS = fps;
        }
    } else
        this->_device->yield();
}

bool Irrlicht::Screen::setFullscreen(bool fullscreen) {
    if (_fullscreen == fullscreen)
        return (false);
    this->_device->closeDevice();
    this->_device->run();
    this->_device->drop();
    _fullscreen = fullscreen;
    this->_device = irr::createDevice(_driverType, irr::core::dimension2d<irr::u32>(_width, _height), _colorDepth,
                                     _fullscreen, false, _vsync, nullptr);
    this->_driver = _device->getVideoDriver();
    return (true);
}

bool Irrlicht::Screen::setWindowSize(int width, int height) {
    if (_width == width && _height == height)
        return (false);
    this->_device->closeDevice();
    this->_device->run();
    this->_device->drop();
    this->_width = width;
    this->_height = height;
    this->_device = irr::createDevice(_driverType, irr::core::dimension2d<irr::u32>(_width, _height), _colorDepth,
                                      _fullscreen, false, _vsync, nullptr);
    this->_driver = _device->getVideoDriver();
    return (true);
}

bool Irrlicht::Screen::setVsync(bool vsync) {
    if (_vsync == vsync)
        return (false);
    this->_device->closeDevice();
    this->_device->run();
    this->_device->drop();
    _vsync = vsync;
    this->_device = irr::createDevice(_driverType, irr::core::dimension2d<irr::u32>(_width, _height), _colorDepth,
                                      _fullscreen, false, _vsync, nullptr);
    this->_driver = _device->getVideoDriver();
    return (true);
}
