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
#include "../game-scene/GameScene.hpp"
#include "../game-scene/main-menu/MainMenu.hpp"
#include "../game-scene/options-menu/OptionsMenu.hpp"
#include "../game-scene/load-game-menu/LoadGameMenu.hpp"

#if defined(_WIN32) && !defined(__GNUC__)
#define driverType irr::video::EDT_DIRECT3D9
#else
#define driverType irr::video::EDT_OPENGL
#endif

Irrlicht::Screen::Screen(int width, int height, int colorDepth, bool fullscreen, bool vsync) :
    _width(width),
    _height(height),
    _colorDepth(colorDepth),
    _fullscreen(fullscreen),
    _vsync(vsync),
    _driverType(driverType),
    _device(nullptr),
    _lastSceneId(0),
    _currentSceneId(0),
    isGameClosed(false)
{
    this->_device = irr::createDevice(
        this->_driverType,
        irr::core::dimension2d<irr::u32>(
            this->_width,
            this->_height
        ),
        this->_colorDepth,
        this->_fullscreen,
        false,
        this->_vsync,
        &this->_eventReceiver
    );
    this->_driver = this->_device->getVideoDriver();
    this->_guienv = (this->_device->getGUIEnvironment());
    this->_smgr = (this->_device->getSceneManager());
    this->_device->setResizable(true);
}


bool Irrlicht::Screen::display() {
    static int lastFPS = -1;

    if (this->_device->isWindowActive())
    {
        this->_driver->beginScene(true, true, irr::video::SColor(255, 101, 101, 140));
        if (this->_smgr)
            this->_smgr->drawAll();
        if (this->_guienv)
            this->_guienv->drawAll();
        if (this->_currentSceneId != 0)
            if (!this->getCurrentGameScene().update()) {
                this->setGameClosed(true);
                return (false);
            }
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
    return (this->setWindowAttributes(this->_width, this->_height, this->_colorDepth, fullscreen, this->_vsync));
}

bool Irrlicht::Screen::setWindowSize(int width, int height) {
    return (this->setWindowAttributes(width, height, this->_colorDepth, this->_fullscreen, this->_vsync));
}

bool Irrlicht::Screen::setVsync(bool vsync) {
    return (this->setWindowAttributes(this->_width, this->_height, this->_colorDepth, this->_fullscreen, vsync));
}

bool Irrlicht::Screen::setWindowAttributes(int width, int height, int colorDepth, bool fullscreen, bool vsync) {
    if (this->_vsync == vsync && this->_width == width && this->_height == height && this->_fullscreen == fullscreen && this->_colorDepth == colorDepth)
        return (true);
    this->_device->closeDevice();
    this->_device->run();
    this->_device->drop();
    this->_vsync = vsync;
    this->_fullscreen = fullscreen;
    this->_height = height;
    this->_width = width;
    this->_colorDepth = colorDepth;
    this->_device = irr::createDevice(
        this->_driverType,
        irr::core::dimension2d<irr::u32>(
            this->_width,
            this->_height
        ),
        this->_colorDepth,
        this->_fullscreen,
        false,
        this->_vsync,
        &this->_eventReceiver
    );
    this->_guienv = this->_device->getGUIEnvironment();
    this->_smgr = this->_device->getSceneManager();
    this->_driver = this->_device->getVideoDriver();
    this->_device->getCursorControl()->setVisible(false);
    return (true);
}

unsigned Irrlicht::Screen::addGameSceneGame(const std::string &name) {
    this->_lastSceneId++;
    this->_scenes.emplace_back(new GameScene{*this, name, this->_lastSceneId});
    return (this->_lastSceneId);
}

unsigned Irrlicht::Screen::addGameSceneMainMenu(const std::string &name) {
    this->_lastSceneId++;
    this->_scenes.emplace_back(new MainMenu{*this, name, this->_lastSceneId});
    return (this->_lastSceneId);
}

unsigned Irrlicht::Screen::addGameSceneOptions(const std::string &name) {
    this->_lastSceneId++;
    this->_scenes.emplace_back(new OptionsMenu{*this, name, this->_lastSceneId});
    return (this->_lastSceneId);
}

unsigned Irrlicht::Screen::addGameSceneLoadGame(const std::string &name) {
    this->_lastSceneId++;
    this->_scenes.emplace_back(new LoadGameMenu{*this, name, this->_lastSceneId});
    return (this->_lastSceneId);
}

Irrlicht::GameScene &Irrlicht::Screen::getCurrentGameScene() {
    return (*this->_scenes.at(_currentSceneId - 1));
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
            this->resetButtonsStates();
            return (true);
        }
    }
    return false;
}

Irrlicht::EventReceiver &Irrlicht::Screen::getEventReceiver() {
    return (this->_eventReceiver);
}

irr::video::IVideoDriver *Irrlicht::Screen::getDriver() {
    return (this->_driver);
}

irr::scene::ISceneManager *Irrlicht::Screen::getSmgr() {
    return (this->_smgr);
}

irr::IrrlichtDevice *Irrlicht::Screen::getDevice() {
    return (this->_device);
}

irr::gui::IGUIEnvironment *Irrlicht::Screen::getGuiEnv() {
    return (this->_guienv);
}

Irrlicht::GameScene &Irrlicht::Screen::getGameSceneById(unsigned id) {
    size_t i;
    for (i = 0; i != this->_lastSceneId; i++)
        if (this->_scenes[i]->id == id)
            break;
    return (*this->_scenes.at(i));
}

bool Irrlicht::Screen::isValidGetterId(unsigned id) {
    size_t i;
    for (i = 0; i != this->_lastSceneId; i++)
        if (this->_scenes[i]->id == id)
            return (true);
    return (false);
}

bool Irrlicht::Screen::isValidGetterName(const std::string& name) {
    size_t i;
    for (i = 0; i != this->_lastSceneId; i++)
        if (this->_scenes[i]->sceneName == name)
            return (true);
    return (false); //TODO NEW EXCEPTION
}

Irrlicht::GameScene &Irrlicht::Screen::getGameSceneByName(const std::string& name) {
    size_t i;
    for (i = 0; i != this->_lastSceneId; i++)
        if (this->_scenes[i]->sceneName == name)
            break;
    return (*this->_scenes.at(i));
}

void Irrlicht::Screen::setCursorVisible(bool cursor) {
    this->_device->getCursorControl()->setVisible(cursor);
}

void Irrlicht::Screen::setGameClosed(bool close) {
    this->isGameClosed = close;
}

void Irrlicht::Screen::resetButtonsStates() {
    this->_eventReceiver.resetButtonsStates();
}
