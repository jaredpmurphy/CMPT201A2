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
    unsigned int _level_num;
    unsigned int _num_ghosts;
    unsigned int _req_coins;
    unsigned int _collected_coins;
    unsigned int _max_lives;
    unsigned int _current_lives;
    coin _active_coin;
    vec2 _player_spawn_coord;
    vec2 _door_coord;
    vec2 _player_cur_coord;
    ghost _active_ghosts[MAX_GHOSTS];
} level;


/** Creates a level struct and populates with relevant game info.
    @param level_num ie level 1, level 2...
    @param max_lives how many times can player die.
    @param num_ghosts number of ghosts to spawn in this level.
    @param req_coins how many coins must be collected before door opens.
    @return level: a newly populated level struct */
level create_level(unsigned int level_num, unsigned int max_lives, unsigned int num_ghosts, unsigned int req_coins);

/** Prints the level in the given game window.
    Level map is printed, then ghosts, then coins, then player.
    @param lvl pointer to current level.
    @param win ncurses window to display game in. */
void display_level(level *lvl, WINDOW *win);

ghost spawn_ghost();

coin spawn_coin();

/** If movement is valid, move player in direction supplied.
    @param lvl current level being played.
    @param direction direction to move player, ie use macros defined in common.h UP, DOWN, LEFT, RIGHT */
void move_player(level *lvl, vec2 direction);

/** Will move all ghosts in a level one tile, random direction 
    If ghost hits player (they occupy same coords), the player loses a life and returns to spawn.
    If player has 0 lives when hit, game over screen will display, which allows resetting coins and lives and respawning or quitting.
    @param lvl pointer to current level. */
void move_ghosts(level *lvl);

#endif