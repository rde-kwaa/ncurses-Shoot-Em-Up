#include <ncurses.h>
#include <iostream>
#include <unistd.h>
#include <list>
#include "Entity.hpp"
#include "Player.hpp"

#define DELAY 20000

void windowClean(WINDOW *win) {
	wclear(win);
	box(win, 0, 0);
}

void playerUpdate(WINDOW *win, Player playerOne,int yMax, int xMax){
	mvwprintw(win, playerOne.v, playerOne.h, "0");
}

void objectUpdate(WINDOW *win, std::list<Entity> &listOfPlayer, int yMax, int xMax){
	std::list<Entity>::iterator it = listOfPlayer.begin();
	it = listOfPlayer.begin();
	int  next_x;
	// TODO -- loop list

	 next_x = it->h + it->speed;

	if (next_x >= xMax || next_x < 0) {
		it->speed*= -1;
	} else {
		it->h += it->speed;
	}
	mvwprintw(win, 5+2, it->h, "0");
}


int main(int argc, char *argv[]) {

	initscr();
    noecho();
    cbreak();

	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);
	yMax -=10;
	xMax -=10;
	WINDOW *win = newwin(yMax, xMax, 0, 0);
	box(win, 0, 0);
	keypad(win, true);

	Player playerOne(1, 1, "0");

 	while(playerOne.alive) {
		
		getmaxyx(stdscr, yMax, xMax);
		yMax -=10;
		xMax -=10;
		clear();
		windowClean(win);
		playerUpdate(win, playerOne, yMax, xMax);
		refresh();
		playerOne.getMove(win, yMax, xMax);
		wrefresh(win);

		usleep(DELAY);
	}

 endwin();
}


