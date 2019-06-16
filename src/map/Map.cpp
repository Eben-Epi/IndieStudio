/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Map.cpp
*/

#include <algorithm>
#include <fstream>
#include "Map.hpp"
#include "../ecs/components/PositionComponent.hpp"
#include "MapException.hpp"
#include "../ecs/components/EntityDropperComponent.hpp"
#include "../ecs/components/PowerUpComponent.hpp"
#include "../ecs/components/HealthComponent.hpp"
#include "../input/AIBrain.hpp"
#include "../ecs/Exceptions.hpp"

Map::Map::Map(Irrlicht::GameScene &gameScene, std::vector<std::unique_ptr<Input::Input>> &inputs, Sound::SoundSystem &soundSystem) :
    _inputs(inputs),
    _ressources(gameScene, soundSystem, this->_core),
    _core(this->_ressources),
    _clock(0)
{
}

Map::Map::Map(Irrlicht::GameScene &gameScene, std::vector<std::unique_ptr<Input::Input>> &inputs, Sound::SoundSystem &soundSystem, std::istream &stream) :
    _inputs(inputs),
    _ressources(
        gameScene,
        soundSystem,
        this->_core,
        [&inputs](){
    	    std::vector<Input::Input *> result;

    	    for (auto &val : inputs)
    	        result.push_back(&*val);
    	    return result;
        }(),
        {
    	    [&stream](){
                std::string header;
	        unsigned result;

		stream >> header >> result;
		if (header != "BombermanMap")
		    throw ECS::InvalidSerializedStringException("Invalid serialized string: Map Header invalid");
		return result;
	    }(),
	    [&stream](){
                unsigned result;

                stream >> result;
                return result;
	    }()
	}
    ),
    _core(this->_ressources, stream),
    _clock(0)
{
}

std::vector<ECS::Entity *> Map::Map::getPlayersAlive()
{
    return this->_core.getEntitiesByName("Player");
}

bool Map::Map::update()
{
    if (this->_clock < 2 * FRAME_RATE) {
    	if (this->_clock++ == 0) {
            this->_core.update();
            this->_ressources.soundSystem.setBackgroundMusic("battle_music", 45); // tmp
	    this->_ressources.soundSystem.playSoundOverBackgroundMusic("announcer_ready_go");
        }
        return true;
    }

    if (this->_clock % 10 == 0)
        this->_core.update();

    if (this->_ended)
        return this->_clock++ < 5 * FRAME_RATE;

    auto players = this->_core.getEntitiesByName("Player");

    if (players.size() < 2) {
        this->_ressources.soundSystem.playSound("announcer_game");
        this->_ressources.soundSystem.stopBackgroundMusic();
        this->_ended = true;
        for (ECS::Entity *entity : players)
	    reinterpret_cast<ECS::HealthComponent &>(entity->getComponentByName("Health")).invunerabilityTimeLeft = 99999;
    }
    return true;
}

std::vector<unsigned> Map::Map::_XPairYPairSidesWallGenerator(ECS::Vector2<unsigned> sizeMap)
{
    unsigned maxSize = sizeMap.x * sizeMap.y;
    bool yShift;
    bool xShift;
    std::vector<unsigned> wallPos;

    for (unsigned j = 0; j < maxSize; ++j) {
        yShift = (j / sizeMap.x) >= sizeMap.y / 2;
        xShift = (j % sizeMap.x) >= sizeMap.x / 2;
        if ((j / sizeMap.x + yShift) % 2 && (j % sizeMap.x + xShift) % 2)
            wallPos.push_back(j);
    }
    return (wallPos);
}

std::vector<unsigned> Map::Map::_XImpairYImpairSidesWallGenerator(ECS::Vector2<unsigned> sizeMap)
{
    unsigned maxSize = sizeMap.x * sizeMap.y;
    std::vector<unsigned> wallPos;

    for (unsigned j = 0; j < maxSize; ++j) {
        if ((j / sizeMap.x) % 2 && (j % sizeMap.x) % 2)
            wallPos.push_back(j);
    }
    return (wallPos);
}

std::vector<unsigned> Map::Map::_XPairYImpairSidesWallGenerator(ECS::Vector2<unsigned> sizeMap)
{
    unsigned maxSize = sizeMap.x * sizeMap.y;
    bool xShift;
    std::vector<unsigned> wallPos;

    for (unsigned j = 0; j < maxSize; ++j) {
        xShift = (j % sizeMap.x) >= sizeMap.x / 2;
        if ((j / sizeMap.x) % 2 && (j % sizeMap.x + xShift) % 2)
            wallPos.push_back(j);
    }
    return (wallPos);
}

std::vector<unsigned> Map::Map::_XImpairYPairSidesWallGenerator(ECS::Vector2<unsigned> sizeMap)
{
    unsigned maxSize = sizeMap.x * sizeMap.y;
    bool yShift;
    std::vector<unsigned> wallPos;

    for (unsigned j = 0; j < maxSize; ++j) {
        yShift = (j / sizeMap.x) >= sizeMap.y / 2;
        if ((j / sizeMap.x + yShift) % 2 && (j % sizeMap.x) % 2)
            wallPos.push_back(j);
    }
    return (wallPos);
}

std::vector<unsigned> Map::Map::_generateWallBlocksPos(ECS::Vector2<unsigned> sizeMap)
{
    bool pairX = (sizeMap.x + 1) % 2;
    bool pairY = (sizeMap.y + 1) % 2;

    switch (pairX + (pairY * 2)) {
        case 1:
            return (this->_XPairYImpairSidesWallGenerator(sizeMap));
        case 2:
            return (this->_XImpairYPairSidesWallGenerator(sizeMap));
        case 3:
            return (this->_XPairYPairSidesWallGenerator(sizeMap));
        default:
            return (this->_XImpairYImpairSidesWallGenerator(sizeMap));
    }

}

std::vector<unsigned> Map::Map::_generateAirBlocksPos(ECS::Vector2<unsigned> sizeMap)
{
    unsigned maxSize = sizeMap.x * sizeMap.y;
    unsigned maxSizeM = maxSize - sizeMap.x;
    unsigned doubleSize = sizeMap.x * 2;
    unsigned maxSizeDM = maxSize - doubleSize;
    std::vector<unsigned> airPos;

    airPos = {0, 1, sizeMap.x - 2, sizeMap.x - 1, sizeMap.x, doubleSize - 1, maxSizeDM, maxSizeM - 1, maxSizeM, maxSizeM + 1, maxSize - 2, maxSize - 1};
    return (airPos);
}

void Map::Map::_setEntityComponentPosition(ECS::Entity &entity, ECS::Point pos)
{
    reinterpret_cast<ECS::PositionComponent &>(entity.getComponentByName("Position")).pos = pos;
}

void Map::Map::_setEntityDropperComponentInBrick(ECS::Entity &brick, unsigned randNum, std::map<std::string, unsigned> &ratiosBonus)
{
    ECS::EntityDropperComponent &entityDropper = reinterpret_cast<ECS::EntityDropperComponent &>(brick.getComponentByName("EntityDropper"));

    for (auto &val : ratiosBonus) {
        if (randNum < val.second) {
            entityDropper.item = val.first;
            break;
        }
        randNum -= val.second;
    }
}

void Map::Map::_setArenaWallAround(ECS::Vector2<unsigned> sizeMap)
{
    for (int i = -1; i < (int)sizeMap.x + 1; ++i) {
        this->_setEntityComponentPosition(this->_core.makeEntity("Bedrock"), {(double)(i * TILESIZE), -1 * TILESIZE});
        this->_setEntityComponentPosition(this->_core.makeEntity("Bedrock"), {(double)(i * TILESIZE), (double)(sizeMap.y * TILESIZE)});
    }
    for (int i = 0; i < (int)sizeMap.y; ++i) {
        this->_setEntityComponentPosition(this->_core.makeEntity("Bedrock"), {-1 * TILESIZE, (double)(i * TILESIZE)});
        this->_setEntityComponentPosition(this->_core.makeEntity("Bedrock"), {(double)(sizeMap.x * TILESIZE), (double)(i * TILESIZE)});
    }
}

void Map::Map::generateMap(ECS::Vector2<unsigned> sizeMap, unsigned brickRatio, const std::vector<PlayerConfig> &players, std::map<std::string, unsigned> ratiosBonus)
{
    std::vector<unsigned> airBlocksPos = this->_generateAirBlocksPos(sizeMap);
    std::vector<unsigned> wallBlocksPos = this->_generateWallBlocksPos(sizeMap);
    unsigned randNum;
    unsigned bonus = ratiosBonus["Bonus"];
    ECS::Point position;

    this->_ressources.mapSize = sizeMap;
    ratiosBonus.erase(
        std::find_if(
            ratiosBonus.begin(),
            ratiosBonus.end(),
            [](std::pair<const std::string, unsigned> &val) {
                return val.first == "Bonus";
            }
        )
    );
    if (sizeMap.x < 4 || sizeMap.y < 4)
        throw MapTooSmallException("Map is too small in x or in y (< 4).");
    this->_ai.clear();
    this->_ressources.inputs = {};
    for (size_t i = 0; i < players.size(); i++) {
    	auto &player = players[i];

    	if (player.input) {
	    this->_ressources.inputs.push_back(player.input);
	} else {
    	    this->_ai.emplace_back(new Input::AIBrain(i, this->_core));
	    this->_ressources.inputs.push_back(&*this->_ai.back());
    	}
        this->_setEntityComponentPosition(
            this->_core.makeEntity(player.entity),
            {
                TILESIZE / 16. + TILESIZE * (sizeMap.x - 1) * (player.pos % 2),
                TILESIZE / 16. + TILESIZE * (sizeMap.x - 1) * (player.pos / 2)
            }
        );
    }
    this->_setArenaWallAround(sizeMap);
    for (unsigned i = 0; i < sizeMap.x * sizeMap.y - 2; ++i) {
        if (!airBlocksPos.empty() && airBlocksPos[0] == i)
            airBlocksPos.erase(airBlocksPos.begin());
        else {
            position = {(double)((i % sizeMap.x) * TILESIZE), (double)((i / sizeMap.x) * TILESIZE)};
            if (!wallBlocksPos.empty() && wallBlocksPos[0] == i) {
                this->_setEntityComponentPosition(this->_core.makeEntity("Wall"), position);
                wallBlocksPos.erase(wallBlocksPos.begin());
            } else {
                randNum = rand() % 10000;
                if (randNum < brickRatio) {
                    ECS::Entity &brick = this->_core.makeEntity("Brick");
                    this->_setEntityComponentPosition(brick, position);
                    if (!ratiosBonus.empty() && bonus > 0 && rand() % 100 < bonus) {
                        unsigned total = 0;

                        std::for_each(
                            ratiosBonus.begin(),
                            ratiosBonus.end(),
                            [&total](const std::pair<std::string, unsigned> &val) {
                                total += val.second;
                            }
                        );
                        this->_setEntityDropperComponentInBrick(brick, rand() % (total ? total : 1), ratiosBonus);
                    }
                }
            }
        }
    }
}

std::ostream& Map::Map::serialize(std::ostream &stream) const
{
    stream << "BombermanMap " << this->_ressources.mapSize.x << " " << this->_ressources.mapSize.y << std::endl;
    return stream << this->_core;
}

std::ostream &operator<<(std::ostream &stream, const Map::Map &map)
{
    return map.serialize(stream);
}

bool Map::Map::save(const std::string &path)
{
	std::ofstream stream(path);

	if (!stream.is_open())
		return false;
	stream << *this << std::endl;
	return true;
}