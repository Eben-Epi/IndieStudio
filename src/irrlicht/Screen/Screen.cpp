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
#include "../GameScene/GameScene.hpp"

Irrlicht::Screen::Screen(int width, int height, int colorDepth, bool fullscreen, bool vsync) : _width(width), _height(height), _colorDepth(colorDepth), _fullscreen(fullscreen), _vsync(vsync) { //TODO FULLSCREEN, SET WINDOW SIZE AND TYPE, ENABLE VSYNC
    this->_driverType = irr::video::EDT_OPENGL;
    this->_device = irr::createDevice(_driverType, irr::core::dimension2d<irr::u32>(_width, _height), _colorDepth,
                                 _fullscreen, false, _vsync, &this->_eventReceiver);
    this->_driver = _device->getVideoDriver();
    this->_guienv = nullptr;
    this->_smgr = nullptr;
    this->_device->setResizable(true);
    this->_currentSceneId = 0;
    this->_lastSceneId = 0;
}


bool Irrlicht::Screen::display() { //TODO COLOR SCENE
    static int lastFPS = -1;
    if (this->_device->isWindowActive())
    {
        this->getCurrentGameScene().update();
        this->_driver->beginScene(true, true, irr::video::SColor(255,200,200,200));
        if (this->_smgr)
            this->_smgr->drawAll();
        if (this->_guienv)
            this->_guienv->drawAll();
        this->_driver->endScene();

        int fps = this->_driver->getFPS();

        if (lastFPS != fps) {
            irr::core::stringw str = WINDOW_NAME" [";
            str += this->_driver->getName();
            str += "] FPS:";
            str += fps;
            lastFPS = fps;
            this->_device->setWindowCaption(str.c_str());
        }
    } else
        this->_device->yield();
    return this->_device->run();
}

bool Irrlicht::Screen::setFullscreen(bool fullscreen) {
    if (_fullscreen == fullscreen)
        return (false);
    this->_device->closeDevice();
    this->_device->run();
    this->_device->drop();
    _fullscreen = fullscreen;
    this->_device = irr::createDevice(_driverType, irr::core::dimension2d<irr::u32>(_width, _height), _colorDepth,
                                     _fullscreen, false, _vsync, &this->_eventReceiver);
    this->_guienv = nullptr;
    this->_smgr = nullptr;
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
                                      _fullscreen, false, _vsync, &this->_eventReceiver);
    this->_guienv = nullptr;
    this->_smgr = nullptr;
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
                                      _fullscreen, false, _vsync, &this->_eventReceiver);
    this->_guienv = nullptr;
    this->_smgr = nullptr;
    this->_driver = _device->getVideoDriver();
    return (true);
}

unsigned Irrlicht::Screen::addGameScene(const std::string &name) {
    this->_scenes.emplace_back(new GameScene{*this, name, this->_lastSceneId++});
    return (_lastSceneId);
}

Irrlicht::GameScene &Irrlicht::Screen::getCurrentGameScene() {
    return (*this->_scenes.at(_currentSceneId));
}

bool Irrlicht::Screen::setCurrentGameScene(unsigned id) {
    if (id <= _lastSceneId) {
        this->_currentSceneId = id;
        return (true);
    }
    return (false);
}

bool Irrlicht::Screen::setCurrentGameScene(const std::string &name) {
    for (auto &gameScene : this->_scenes) {
        if (gameScene->sceneName == name) {
            this->_currentSceneId = gameScene->id;
            return (true);
        }
    }
    return false;
}

Irrlicht::EventReceiver &Irrlicht::Screen::getEventReceiver()
{
    return (this->_eventReceiver);
}