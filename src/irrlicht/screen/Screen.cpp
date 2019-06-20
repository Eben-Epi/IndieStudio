//
// Created by Eben on 27/05/2019.
//

#include <iostream>
#include <irrlicht/irrlicht.h>
#include <algorithm>
#include <fstream>
#include "Screen.hpp"
#include "../game-scene/GameScene.hpp"
#include "../game-scene/main-menu/MainMenu.hpp"
#include "../game-scene/keys-managing-menu-new/KeysManagingMenuNew.hpp"
#include "../game-scene/load-game-menu/LoadGameMenu.hpp"
#include "../game-scene/new-game-menu/NewGameMenu.hpp"
#include "../game-scene/how-to-play/HowToPlayMenu.hpp"
#include "../game-scene/pause-menu/PauseMenu.hpp"
#include "../game-scene/demo-menu/DemoMenu.hpp"
#include "../Exceptions.hpp"
#include "../game-scene/keys-managing-menu-load/KeysManagingMenuLoad.hpp"
#include "../../config.hpp"
#include "../game-scene/game/Game.hpp"
#include "../../ecs/Exceptions.hpp"

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
    isGameClosed(false)
{
    for (auto &sound_name : sound_to_load)
        this->soundSystem.loadSound(sound_name);
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
    this->_device->getLogger()->setLogLevel(irr::ELL_ERROR);
    this->_driver = this->_device->getVideoDriver();
    this->_guienv = (this->_device->getGUIEnvironment());
    this->_smgr = (this->_device->getSceneManager());
    this->_screenSize = this->_driver->getScreenSize();
    this->_device->setResizable(true);
}

bool Irrlicht::Screen::display() {
    static int lastFPS = -1;
    auto &gameScene = this->getCurrentGameScene();

    if (this->_device->isWindowActive())
    {
        this->_driver->beginScene(true, true, irr::video::SColor(255, 101, 101, 140));
        if (this->_smgr)
            this->_smgr->drawAll();
        if (this->_guienv)
            this->_guienv->drawAll();
        if (!gameScene.update()) {
            if (&getCurrentGameScene() == &gameScene) {
                this->setGameClosed(true);
                return (false);
            }
            this->_scenes.erase(std::find_if(
                    this->_scenes.begin(),
                    this->_scenes.end(),
                    [&gameScene](std::unique_ptr<GameScene>&scene){
                        return &gameScene == &*scene;
                    }));
        }
        this->_driver->endScene();
        if (this->_screenSize != this->_driver->getScreenSize()) {
            this->_screenSize = this->_driver->getScreenSize();
            this->getCurrentGameScene().addCamera(320, 500, -320, 320, 0, -319);
        }
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
    this->_device->getLogger()->setLogLevel(irr::ELL_ERROR);
    this->_guienv = this->_device->getGUIEnvironment();
    this->_smgr = this->_device->getSceneManager();
    this->_driver = this->_device->getVideoDriver();
    this->_screenSize = this->_driver->getScreenSize();
    this->_device->getCursorControl()->setVisible(false);
    return (true);
}

void Irrlicht::Screen::addGameSceneGame(const std::string &name, std::vector<Map::Map::PlayerConfig> configs) {
    this->_scenes.emplace_back(new Game{*this, name, static_cast<unsigned>(this->_scenes.size()), configs});
}

void Irrlicht::Screen::addGameSceneGame(const std::string &name, std::vector<std::unique_ptr<Input::Input>> &inputs, const std::string &path) {
	std::ifstream file(path);

	if (!file.is_open())
		throw ECS::InvalidSerializedStringException("Cannot open file save.txt");
	this->_scenes.emplace_back(new Game{*this, name, static_cast<unsigned>(this->_scenes.size()), inputs, file});
}

void Irrlicht::Screen::addGameSceneMainMenu(const std::string &name) {
    this->_scenes.emplace_back(new MainMenu{*this, name, static_cast<unsigned>(this->_scenes.size())});
}

void Irrlicht::Screen::addGameSceneNewGameMenu(const std::string &name) {
    this->_scenes.emplace_back(new NewGameMenu{*this, name, static_cast<unsigned>(this->_scenes.size())});
}

void Irrlicht::Screen::addGameSceneLoadGameMenu(const std::string &name) {
    this->_scenes.emplace_back(new LoadGameMenu{*this, name, static_cast<unsigned>(this->_scenes.size())});
}

void Irrlicht::Screen::addGameSceneKeysManagingMenuNew(const std::string &name, unsigned playerNb, unsigned iaNb, unsigned soundVolume) {
    this->_scenes.emplace_back(new KeysManagingMenuNew{*this, name, static_cast<unsigned>(this->_scenes.size()), playerNb, iaNb, soundVolume});
}

void Irrlicht::Screen::addGameSceneKeysManagingMenuLoad(const std::string &name, unsigned playerNb, unsigned iaNb, unsigned soundVolume) {
    this->_scenes.emplace_back(new KeysManagingMenuLoad{*this, name, static_cast<unsigned>(this->_scenes.size()), playerNb, iaNb, soundVolume});
}

void Irrlicht::Screen::addGameSceneDemoMenu(const std::string &name) {
    this->_scenes.emplace_back(new DemoMenu{*this, name, static_cast<unsigned>(this->_scenes.size())});
}

Irrlicht::GameScene &Irrlicht::Screen::getCurrentGameScene() {
    for (auto &scene : this->_scenes)
        if (scene->sceneName == this->_currentSceneName)
            return (*scene);
    throw NoSuchSceneException("Cannot find scene with name " + this->_currentSceneName);
}

bool Irrlicht::Screen::setCurrentGameScene(const std::string &name) {
    for (auto &gameScene : this->_scenes) {
        if (gameScene->sceneName == name) {
            this->_currentSceneName = gameScene->sceneName;
            this->resetButtonsStates();
            return (true);
        }
    }
    throw NoSuchSceneException("Cannot find scene with name " + name);
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
    for (i = 0; i != this->_scenes.size(); i++)
        if (this->_scenes[i]->id == id)
            return (*this->_scenes.at(i));
    throw NoSuchSceneException("Cannot find entity with id " + std::to_string(id));
}

bool Irrlicht::Screen::isValidGetterId(unsigned id) {
    size_t i;
    for (i = 0; i != this->_scenes.size(); i++)
        if (this->_scenes[i]->id == id)
            return (true);
    return (false);
}

bool Irrlicht::Screen::isValidGetterName(const std::string& name) {
    size_t i;
    for (i = 0; i != this->_scenes.size(); i++)
        if (this->_scenes[i]->sceneName == name)
            return (true);
    return (false);
}

Irrlicht::GameScene &Irrlicht::Screen::getGameSceneByName(const std::string& name) {
    size_t i;
    for (i = 0; i != this->_scenes.size(); i++)
        if (this->_scenes[i]->sceneName == name)
            return (*this->_scenes.at(i));
    throw NoSuchSceneException("Cannot find entity with name " + name);
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

void Irrlicht::Screen::cleanGameScenes() {
    for (size_t i = 0; i != this->_scenes.size(); i++)
        if (this->_scenes[i]->sceneName != this->_currentSceneName)
            this->_scenes.erase(this->_scenes.begin() + i);
}
