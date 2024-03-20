#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#include "level.h"


void prompt_quit() {

}

/** Pause game until 'p' is pressed */
void pause_game() {

}

/** Display initial splashscreen, with options to start chosen level or quit game */
void display_splash() {

}

void close_game() {
	clear();
	refresh();
	endwin();
	exit(0);
}

/** This will draw all level entities.
	This include walls/player/ghosts/coins */
void draw_level() {

}



int main() {
	WINDOW *game_win;
	int ch;
	bool should_close = false;

	unsigned int lives = 3;
	unsigned int coins = 0;

	initscr();
	noecho();

	display_splash();

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
				break;
			case KEY_DOWN:
				//move down
				break;
			case KEY_RIGHT:
				//move right
				break;
			case KEY_LEFT:
				//move left
				break;
			case ' ':
				//collect coin if available when Spacebar pressed
				break;
			default:
				//none
				break;
		}

	refresh();
	}

	getch();
	endwin();
}
