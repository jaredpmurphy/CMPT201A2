#ifndef LEVEL_H
#define LEVEL_H

#include "common.h"
#include "ghost.h"
#include "player.h"

/** Contains functions for creation of levels and queries for level info

*/

#define MAX_AREAS 20
#define MAX_GHOSTS 20

/** Simple struct to hold info of a coin */
typedef struct {
    char symbol = COIN;
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
    area _ghost_spawn_areas[MAX_AREAS];
    area _coin_spawn_areas[MAX_AREAS];
    ghost _active_ghosts[MAX_GHOSTS];
} level;


/** Creates a level struct based on params and returns it*/
level create_level(unsigned int level_num, unsigned int num_ghosts,
                    unsigned int req_coins, vec2 player_spawn_coord,
                    vec2 door_coord, area ghost_spawn_areas[], area coin_spawn_areas);

ghost spawn_ghost();

coin spawn_coin();

player spawn_player();


#endif