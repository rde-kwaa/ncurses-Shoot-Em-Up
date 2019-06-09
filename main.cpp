#include <ncurses.h>
#include <sys/timeb.h>
#include <unistd.h>
#include <cstdlib>
#include <iostream>
#include <list>
#include "Entity.hpp"
#include "Player.hpp"

#define DELAY 20000

void windowClean(WINDOW *win) {
	wclear(win);
	box(win, 0, 0);
}

void playerUpdate(WINDOW *win, Player playerOne, int yMax, int xMax) {
	mvwprintw(win, playerOne.getV(), playerOne.getH(), "0");
}

void objectUpdate(WINDOW *win, std::list<Entity> &listOfPlayer, int yMax, int xMax) {
	std::list<Entity>::iterator it = listOfPlayer.begin();
	it = listOfPlayer.begin();
	int next_x;
	// TODO -- loop list

	next_x = it->getH() + it->getSpeed();

	if (next_x >= xMax || next_x < 0) {
		it->setSpeed(it->getSpeed() * -1);
	} else {
		it->setH(it->getH() + it->getV());
	}
	mvwprintw(win, 5 + 2, it->getH(), "0");
}

void menu(WINDOW *win, int xMax, int yMax) {
	int x = xMax / 2 - 8;
	int y = yMax / 2 - 2;
	std::string items[3] = {"NEW GAME", "HELP", "QUIT"};
	int item;
	int highlight = 0;
	int ws = 0;
	std::string s;

	while (1) {
		mvwprintw(win, y - 2, x + 4, "Rush-Type");
		for (int i = 0; i < 3; i++) {
			if (i == highlight)
				wattron(win, A_STANDOUT);
			s = items[i].c_str();
			(strlen(s.c_str()) > 5) ? ws = 4 : ws = 6;
			// print at centered coordinate. c_str is to cast as it only takes char *.
			mvwprintw(win, i + y + 1, x + 1, "%*s%*s",
					  (8 + strlen(s.c_str()) / 2), s.c_str(), ws, " ");
			wattroff(win, A_STANDOUT);
		}
		item = wgetch(win);
		wrefresh(win);
		switch (item) {
			case KEY_UP:
				highlight--;
				(highlight == -1) ? highlight = 0 : 0;
				break;
			case KEY_DOWN:
				highlight++;
				(highlight == 3) ? highlight = 2 : 0;
				break;
			default:
				break;
		}
		if (item == 10)
			break;
	}
}

int getMilliCount() {
	timeb tb;
	ftime(&tb);
	int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
	return nCount;
}

int getMilliSpan(int nTimeStart) {
	int nSpan = getMilliCount() - nTimeStart;
	if (nSpan < 0)
		nSpan += 0x100000 * 1000;
	return nSpan;
}

void updateTime(WINDOW *win, int xMax, int milliSecondsElapsed) {
}

int main(int argc, char *argv[]) {
	initscr();
	noecho();
	cbreak();

	int start = getMilliCount();
	int milliSecondsElapsed;
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);
	yMax -= 10;
	xMax -= 10;
	WINDOW *win = newwin(yMax, xMax, 0, 0);
	nodelay(win, TRUE);

	box(win, 0, 0);
	keypad(win, true);
	curs_set(0);  // hides the default screen cursor.
	menu(win, xMax, yMax);

	Player playerOne(1, 1, "0");
	while (playerOne.alive) {
		milliSecondsElapsed = getMilliSpan(start) / 1000;  // grabs current time

		getmaxyx(stdscr, yMax, xMax);
		yMax -= 10;
		xMax -= 10;
		clear();
		windowClean(win);
		mvwprintw(win, 0, xMax / 2, "Time: %d", milliSecondsElapsed);

		playerUpdate(win, playerOne, yMax, xMax);
		refresh();
		playerOne.getMove(win, yMax, xMax);
		wrefresh(win);

		usleep(DELAY);
	}

	endwin();
}
