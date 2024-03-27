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

}

/** Display initial splashscreen, with options to start chosen level or quit game */
int splash_screen() {
	//Display splash logo/message howto play game etc.
	//Level 1 return 1
	return 1;
	//Level 2 return 2
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
	keypad(stdscr, TRUE);
	game_win = newwin(30,80,3,0);

	level level_one = create_level(1, 3, 3, 3);
	level level_two = create_level(2, 3, 5, 7);

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

	while (!should_close) {
		ch = getch();
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
				break;
			default:
				//none
				break;
		}
		display_level(current_lvl, game_win);
		wrefresh(game_win);
		refresh();
	}

	getch();
	endwin();
}
