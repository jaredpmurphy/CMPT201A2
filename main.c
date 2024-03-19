#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#include "level.h"

void prompt_quit() {

}

void pause_game() {

}

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
			case 'p':
				pause_game();
	}

	refresh();
	}

	getch();
	endwin();
}
