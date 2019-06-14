/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** config.hpp
*/

#ifndef BOMBERMAN_CONFIG_HPP
#define BOMBERMAN_CONFIG_HPP

#define FRAME_RATE 60

#define TILESIZE 32
#define PLAYERSIZE (TILESIZE - TILESIZE / 8)
#define HARD_MOUVEMENT_SPEED_CAP 12

#define FRAME_TIME 1 / FRAME_RATE

const std::vector<std::string> playerEntities = {
    "Sydney",
    "Alphaone",
    "Faerie",
    "Xenotype"
};

const std::vector<std::string> sound_to_load = {
    "battle_music",
    "ultimate_ready",
    "starman",
    "bip",
    "explode",
    "skull",
    "pop1",
    "announcer_doublekill",
    "announcer_triplekill",
    "pause",
    "ready",
    "game",
    "draw",
    "lonie",
    "cyrak",
    "sydney",
    "gunguy",
    "winner"
};

#endif //BOMBERMAN_CONFIG_HPP
