#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

#include "common.h"
#include "level.h"


void prompt_quit() {

}

/** Pause game until 'p' is pressed */
void pause_game() {
	char ch = ' ';
	while(ch != 'p') {
		mvprintw(15, 15, "*******GAME PAUSED********");
		refresh();
		ch = getch();
	}

}

/** Display initial splashscreen, with options to start chosen level or quit game
	@return int: the level number, or 0 if quit selected */
int splash_screen() {
	//Display splash logo/message howto play game etc.
	//if level one selected, return 1
	return 1;
	//if level 2 selected return 2
	//Quit return 0

}

/** Safely exit the game by closing out the ncurses window */
void close_game() {
	clear();
	refresh();
	endwin();
	exit(0);
}



int main() {
	srand(time(NULL)); // init for random num generation
	WINDOW *game_win; // where the level should be drawn. ~3 lines above will be the lives remaining/info etc..
	int ch;
	bool should_close = false;


	initscr();
	noecho();
	raw();
	curs_set(false);
	keypad(stdscr, TRUE);

	if(has_colors()) {
		start_color();
		init_pair(1, COLOR_WHITE, COLOR_RED); // black on red color: 1 for closed door
		init_pair(2, COLOR_YELLOW, COLOR_BLACK); // yellow on black color: 2 for coins
		init_pair(3, COLOR_RED, COLOR_WHITE); // black on white: 3 for ghosts
		init_pair(4, COLOR_BLACK, COLOR_GREEN); // black on green: 4 for open door
		init_pair(5, COLOR_RED, COLOR_BLACK); // red on black: 5 for hearts
		init_pair(6, COLOR_BLACK, COLOR_MAGENTA); // magenta on black: 6 for player
	}

	game_win = newwin(30,80,3,0);

	level level_one = create_level(1, 3, 7, 3);
	level level_two = create_level(2, 3, 10, 7);

	level *current_lvl;

	switch(splash_screen()) {
		case 0:
			close_game();
			break;
		case 1:
			current_lvl = &level_one;
			break;
		case 2:
			current_lvl = &level_two;
			break;
	}

	display_level(current_lvl, game_win);
	refresh();

	ch = '.';
	while (!should_close) {
		mvprintw(1, 0, "                                                                    ");
		mvprintw(1, 2, "Lives:");
		attron(COLOR_PAIR(5));
		for (int i = 0; i < current_lvl->_current_lives; i++) {
			mvprintw(1, 9+(i*3), "<3");
		}
		attroff(COLOR_PAIR(5));
		mvprintw(1, 20, "Coins: %d/%d", current_lvl->_collected_coins, current_lvl->_req_coins);
		switch (ch) {
			case 'q':
				prompt_quit();
				close_game();
				break;
			case 'p':
				pause_game();
				break;
			case KEY_UP:
				//move up
				move_player(current_lvl, UP);
				break;
			case KEY_DOWN:
				//move down
				move_player(current_lvl, DOWN);
				break;
			case KEY_RIGHT:
				//move right
				move_player(current_lvl, RIGHT);
				break;
			case KEY_LEFT:
				//move left
				move_player(current_lvl, LEFT);
				break;
			case ' ':
				//collect coin if available when Spacebar pressed
				collect_coin(current_lvl);
				break;
			default:
				//none
				break;
		}

		display_level(current_lvl, game_win);
		wrefresh(game_win);
		refresh();
		enemy_check(current_lvl);
		if(current_lvl->game_over) {
			clear();
			wclear(game_win);
			mvprintw(0, 30, "Game Over!!!");
			mvprintw(1, 30, "Press any key to contiue...");
			refresh();
			getch();
			clear();
			refresh();

			switch(splash_screen()) {
			case 0:
				close_game();
				break;
			case 1:
				// recreate level so data is freshly init'd
				level_one = create_level(1, 3, 7, 3);
				current_lvl = &level_one;
				break;
			case 2:
				// recreate level so data is freshly init'd
				level_two = create_level(2, 3, 10, 7);
				current_lvl = &level_two;
				break;
			}
		}
		if(current_lvl->_player_cur_coord.x == current_lvl->_door_coord.x && current_lvl->_player_cur_coord.y == current_lvl->_door_coord.y
			&& current_lvl->_collected_coins >= current_lvl->_req_coins) {
				clear();
				wclear(game_win);
				mvprintw(15, 30, "YOU WON!!!!");
				mvprintw(16, 30, "Press any key to continue...");
				refresh();
				getch();

				switch(splash_screen()) {
				case 0:
					close_game();
					break;
				case 1:
					// recreate level so data is freshly init'd
					level_one = create_level(1, 3, 7, 3);
					current_lvl = &level_one;
					break;
				case 2:
					// recreate level so data is freshly init'd
					level_two = create_level(2, 3, 10, 7);
					current_lvl = &level_two;
					break;
				}
			}

		ch = getch();
	}

	getch();
	endwin();
}
