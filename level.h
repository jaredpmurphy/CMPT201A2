#ifndef LEVEL_H
#define LEVEL_H

#include <ncurses.h>
#include "common.h"
#include "ghost.h"
#include "player.h"

/** Contains functions for creation of levels and queries for level info

*/

#define MAX_GHOSTS 20

/** Simple struct to hold info of a coin */
typedef struct coin_struct {
    vec2 position;
} coin;

/** Holds all data for a level.
    Number of areas in any array must be <= MAX_AREAS (20) */
typedef struct level_struct {
    char _map[30][80];
    unsigned int _level_num;
    unsigned int _num_ghosts;
    unsigned int _req_coins;
    coin _active_coin;
    vec2 _player_spawn_coord;
    vec2 _door_coord;
    ghost _active_ghosts[MAX_GHOSTS];
} level;


/** Creates a level struct and populates with relevant game info.
    @param level_num ie level 1, level 2...
    @param num_ghosts number of ghosts to spawn in this level.
    @param req_coins how many coins must be collected before door opens.
    @return level: a newly populated level struct */
level create_level(unsigned int level_num, unsigned int num_ghosts,
                    unsigned int req_coins);

void display_level(level *lvl, WINDOW *win);

ghost spawn_ghosts();

coin spawn_coin();

player spawn_player();


#endif