#include <ncurses.h>
#include <unistd.h>
#include <iostream>
#include <list>
#include <cstdlib>
#include <sys/timeb.h>
#include "../inc/Entity.hpp"
#include "../inc/Player.hpp"

#define DELAY 20000

void windowClean(WINDOW *win) {
    wclear(win);
    box(win, 0, 0);
}

void playerUpdate(WINDOW *win, Player playerOne,int yMax, int xMax){
	mvwprintw(win, playerOne.getV(), playerOne.getH(), "0");
}

void objectUpdate(WINDOW *win, std::list<Entity> &listOfPlayer, int yMax, int xMax) {
    std::list<Entity>::iterator it = listOfPlayer.begin();
    it = listOfPlayer.begin();
    int next_x;
    // TODO -- loop list

	 next_x = it->getH() + it->getSpeed();

	if (next_x >= xMax || next_x < 0) {
		it->setSpeed(it->getSpeed()* -1);
	} else {
		it->setH(it->getH()+it->getV());
	}
	mvwprintw(win, 5+2, it->getH(), "0");
}

void menu(WINDOW *win, int xMax, int yMax) {
    int x, y;
    int c, i = 0;
    char list[3][9] = {"NEW GAME", "HELP", "QUIT"};
    char item[9];



    for (i = 0; i < 3; i++) {
        x = xMax / 2;
        y = yMax / 2;
        move(10, 10);
        printw("Rush-Type");
        if (i == 0)
            wattron(win, A_STANDOUT);  // highlights the first item.
        else
            wattroff(win, A_STANDOUT);
        sprintf(item, "%-7s", list[i]);
        mvwprintw(win, i + 1, 2, "%s", item);
    }

    wrefresh(win);  // update the terminal screen
    while (c != 'q') {
        c = wgetch(win);
		
        sprintf(item, "%-7s", list[i]);
		
        mvwprintw(win, i + 1, 2, "%s", item);
        // use a variable to increment or decrement the value based on the input.
        switch (c) {
            case KEY_UP:
                i--;
                i = (i < 0) ? 2 : i;
                break;
            case KEY_DOWN:
                i++;
                i = (i > 2) ? 0 : i;
                break;
        }
        // now highlight the next item in the list.
        wattron(win, A_STANDOUT);

        sprintf(item, "%-7s", list[i]);
        mvwprintw(win, i + 1, 2, "%s", item);
        wattroff(win, A_STANDOUT);
    }
}

int getMilliCount(){
	timeb tb;
	ftime(&tb);
	int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
	return nCount;
}

int getMilliSpan(int nTimeStart){
	int nSpan = getMilliCount() - nTimeStart;
	if(nSpan < 0)
		nSpan += 0x100000 * 1000;
	return nSpan;
}

void updateTime(WINDOW *win, int xMax, int milliSecondsElapsed){
	
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
 	while(playerOne._alive) {
		milliSecondsElapsed = getMilliSpan(start) /1000; // grabs current time

		getmaxyx(stdscr, yMax, xMax);
		yMax -=10;
		xMax -=10;
		clear();
		windowClean(win);
		mvwprintw(win, 0, xMax /2, "Time: %d", milliSecondsElapsed);
		
		playerUpdate(win, playerOne, yMax, xMax);
		refresh();
		playerOne.getMove(win, yMax, xMax);
		wrefresh(win);

        usleep(DELAY);
    }

    endwin();
}
