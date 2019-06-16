//
// Created by eben_epitech on 6/16/19.
//

#ifndef BOMBERMAN_GAME_HPP
#define BOMBERMAN_GAME_HPP

#include <vector>
#include <memory>
#include "../GameScene.hpp"
#include "../hud/Button.hpp"
#include "../../../input/AIBrain.hpp"
#include "../../../map/Map.hpp"

namespace Irrlicht
{
    class Game : public GameScene
    {
    public:
	    Game(Screen &screen, const std::string &name, unsigned id, std::vector<Map::Map::PlayerConfig> configs);
	    Game(Screen &screen, const std::string &name, unsigned id, std::vector<std::unique_ptr<Input::Input>> &inputs, std::ifstream &file);
        ~Game() override = default;
        bool update() override;

    private:
        //PROPERTIES
        bool _paused = false;
        bool _hasPaused = false;
        unsigned _clock = 0;
        unsigned _gameClock = 0;
        std::unique_ptr<Map::Map> _map;
        std::vector<std::unique_ptr<Input::Input>> _ais;
    };
}


#endif //BOMBERMAN_GAME_HPP
