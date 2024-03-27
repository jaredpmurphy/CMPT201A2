#include <curses.h>
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>

#include "common.h"
#include "level.h"
#include "level_maps.h"

ghost spawn_ghost() {
    int rx = rand() % 75;
    int ry = rand() % 28;
    if (rx < 3) rx = 3;
    if (ry < 3) ry = 3;
    ghost ret_ghost;
    ret_ghost.position.x = rx;
    ret_ghost.position.y = ry;
    return ret_ghost;
}

coin spawn_coin() {
    int rx = rand() % 75;
    int ry = rand() % 28;
    if (rx < 5) rx = 5;
    if (ry < 5) ry = 5;
    coin ret_coin;
    ret_coin.position.x = rx;
    ret_coin.position.y = ry;
    return ret_coin;
}

/** Creates a level struct and populates with relevant game info.
    @param level_num ie level 1, level 2...
    @param max_lives how many times can player die.
    @param num_ghosts number of ghosts to spawn in this level.
    @param req_coins how many coins must be collected before door opens.
    @return level: a newly populated level struct */
level create_level(unsigned int level_num, unsigned int max_lives, unsigned int num_ghosts, unsigned int req_coins) {
    level ret_level;
    ret_level._level_num = level_num;
    ret_level._num_ghosts = num_ghosts;
    ret_level._max_lives = max_lives;
    ret_level._current_lives = max_lives;
    ret_level._req_coins = req_coins;
    ret_level._collected_coins = 0;
    ret_level._door_coord = new_vec2(28, 79);
    ret_level._player_spawn_coord = new_vec2(1, 2);
    ret_level._player_cur_coord = ret_level._player_spawn_coord;

    for (int i = 0; i < num_ghosts; i++) {
        ret_level._active_ghosts[i] = spawn_ghost();
    }

    ret_level._active_coin = spawn_coin();
    return ret_level;
}


/** Prints the level in the given game window.
    Level map is printed, then ghosts, then coins, then player.
    @param lvl pointer to current level.
    @param win ncurses window to display game in. */
void display_level(level *lvl, WINDOW *win) {
    for (int i = 0; i < 30; i++) {
        mvwprintw(win, i, 0, "%s", level_map[lvl->_level_num][i]);
    }

    for (int i = 0; i < lvl->_num_ghosts; i++) {
        mvwprintw(win, lvl->_active_ghosts[i].position.y, lvl->_active_ghosts[i].position.x, "%c", GHOST);
    }

    mvwprintw(win, lvl->_active_coin.position.y, lvl->_active_coin.position.x, "%c", COIN);
    mvwprintw(win, lvl->_player_cur_coord.y, lvl->_player_cur_coord.x, "%c", PLAYER);

    wrefresh(win);
}

/** If movement is valid, move player in direction supplied.
    @param lvl current level being played.
    @param direction direction to move player, ie use macros defined in common.h UP, DOWN, LEFT, RIGHT */
void move_player(level *lvl, vec2 direction) {
    vec2 dest = new_vec2(lvl->_player_cur_coord.y + direction.y, lvl->_player_cur_coord.x + direction.x);
    char dest_char = level_map[lvl->_level_num][dest.y][dest.x];
    if (dest_char != VWALL && dest_char != HWALLD && dest_char != HWALLU) {
        lvl->_player_cur_coord = dest;
    }
    move_ghosts(lvl);
    return;
}

/** Will move all ghosts in a level one tile, random direction 
    If ghost hits player (they occupy same coords), the player loses a life and returns to spawn.
    If player has 0 lives when hit, game over screen will display, which allows resetting coins and lives and respawning or quitting.
    @param lvl pointer to current level. */
void move_ghosts(level *lvl) {
    return;
}