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
#include "../irr-input/event-receiver/EventReceiver.hpp"
#include "../../sound/SoundSystem.hpp"
#include "../../map/Map.hpp"

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
        GameScene &getCurrentGameScene();
        bool setCurrentGameScene(const std::string &name);
        void cleanGameScenes();
        bool setFullscreen(bool fullscreen);
        bool setVsync(bool vsync);
        bool setWindowSize(int width, int height);
        bool setWindowAttributes(int width, int height, int colorDepth, bool fullscreen, bool vsync);
        void setCursorVisible(bool cursor);
        void setGameClosed(bool close);
        bool isValidGetterId(unsigned id);
        bool isValidGetterName(const std::string& name);
	    void addGameSceneGame(const std::string &name, std::vector<Map::Map::PlayerConfig> configs);
	    void addGameSceneGame(const std::string &name, std::vector<std::unique_ptr<Input::Input>> &inputs, const std::string &file);
        void addGameSceneMainMenu(const std::string &name);
        void addGameSceneNewGameMenu(const std::string &name);
        void addGameSceneLoadGameMenu(const std::string &name);
        void addGameSceneKeysManagingMenuNew(const std::string &name, unsigned playerNb, unsigned iaNb, unsigned soundVolume);
        void addGameSceneKeysManagingMenuLoad(const std::string &name, unsigned playerNb, unsigned iaNb, unsigned soundVolume);
        void addGameSceneDemoMenu(const std::string &name);
        void resetButtonsStates();
        EventReceiver &getEventReceiver();
        GameScene &getGameSceneById(unsigned id);
        GameScene &getGameSceneByName(const std::string& name);
        irr::video::IVideoDriver* getDriver();
        irr::scene::ISceneManager* getSmgr();
        irr::gui::IGUIEnvironment* getGuiEnv();
        irr::IrrlichtDevice *getDevice();

        bool isGameClosed;
        Sound::SoundSystem soundSystem;
    private:
        irr::video::E_DRIVER_TYPE _driverType;
        int _width;
        int _height;
        int _colorDepth;
        bool _fullscreen;
        bool _vsync;
        std::string _currentSceneName;
        std::vector<std::unique_ptr<GameScene>> _scenes;

        //PROPERTIES
        irr::core::dimension2du _screenSize;
        irr::IrrlichtDevice* _device;
        irr::video::IVideoDriver* _driver;
        irr::gui::IGUIEnvironment* _guienv;
        irr::scene::ISceneManager* _smgr;
        EventReceiver _eventReceiver;

        //void drawRect(ECS::Point pos, ECS::Vector2<unsigned> size, Color color = 0xFFFFFF, bool filled = false);

    };
}


#endif //BOMBERMAN_IRRLICHT_HPP
