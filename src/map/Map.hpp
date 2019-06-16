/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Map.hpp
*/

#ifndef INDIESTUDIO_MAP_HPP
#define INDIESTUDIO_MAP_HPP


#include <iostream>
#include "../ecs/Ressources.hpp"
#include "../ecs/ECSCore.hpp"
#include "../ecs/data/Vector2.hpp"
#include "../config.hpp"
#include "../ecs/data/NumericValue.hpp"

namespace Map {

    class Map {

    private:
        std::vector<std::unique_ptr<Input::Input>> &_inputs;
        std::vector<std::unique_ptr<Input::Input>> _ai{};
        ECS::Ressources _ressources;
        ECS::ECSCore _core;
        unsigned _clock = 0;
        bool _ended = false;
        std::vector<unsigned> _XPairYPairSidesWallGenerator(ECS::Vector2<unsigned> sizeMap);
        std::vector<unsigned> _XImpairYImpairSidesWallGenerator(ECS::Vector2<unsigned> sizeMap);
        std::vector<unsigned> _XPairYImpairSidesWallGenerator(ECS::Vector2<unsigned> sizeMap);
        std::vector<unsigned> _XImpairYPairSidesWallGenerator(ECS::Vector2<unsigned> sizeMap);
        std::vector<unsigned> _generateWallBlocksPos(ECS::Vector2<unsigned> sizeMap);
        std::vector<unsigned> _generateAirBlocksPos(ECS::Vector2<unsigned> sizeMap);
        void _setEntityComponentPosition(ECS::Entity &entity, ECS::Point pos);
        void _setEntityDropperComponentInBrick(ECS::Entity &brick, unsigned randNum, std::map<std::string, unsigned> &ratiosBonus);
        void _setArenaWallAround(ECS::Vector2<unsigned> sizeMap);

    public:
    	struct PlayerConfig {
    	    Input::Input *input;
    	    std::string  entity;
    	    unsigned     pos;
    	};

        Map(Irrlicht::GameScene &gameScene, std::vector<std::unique_ptr<Input::Input>> &inputs, Sound::SoundSystem &soundSystem);
        Map(Irrlicht::GameScene &gameScene, std::vector<std::unique_ptr<Input::Input>> &inputs, Sound::SoundSystem &soundSystem, std::istream &stream);
        ~Map() = default;
        bool update();
        void generateMap(ECS::Vector2<unsigned> sizeMap, unsigned brickRatio, const std::vector<PlayerConfig> &players, std::map<std::string, unsigned> ratiosBonus = {{"Bonus", 0}});
        std::vector<ECS::Entity *> getPlayersAlive();
        std::ostream &serialize(std::ostream &stream) const;
        bool save(const std::string &path);
    };
}

std::ostream &operator<<(std::ostream &stream, const Map::Map &map);


#endif //INDIESTUDIO_MAP_HPP
