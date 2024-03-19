#include <stdio.h>
#include <ncurses.h>



int main() {
	WINDOW *w;
	//player
	int ch;

	initscr();
	noecho();
	
	printw("Test");

	refresh();

	getch();
	endwin();
}
