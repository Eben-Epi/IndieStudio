/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** congif.hpp
*/

#ifndef BOMBERMAN_CONGIF_HPP
#define BOMBERMAN_CONGIF_HPP

#define FRAME_RATE 60

#define TILESIZE 32
#define PLAYERSIZE (TILESIZE - TILESIZE / 8)

#define FRAME_TIME 1 / FRAME_RATE

const std::vector<std::string> sound_to_load = {
    "battle_music",
    "ultimate_ready",
    "starman"
};

#endif //BOMBERMAN_CONGIF_HPP
