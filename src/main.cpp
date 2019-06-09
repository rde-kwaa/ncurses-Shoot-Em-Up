#include <ncurses.h>
#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include <sys/timeb.h>
#include "../inc/Entity.hpp"
#include "../inc/Player.hpp"
#include "../inc/Game.hpp"

#define DELAY 20000

void windowClean(WINDOW *win) {
   	werase(win);
    box(win, 0, 0);
}

void playerUpdate(WINDOW *win, Player playerOne){
	mvwprintw(win, playerOne.getV(), playerOne.getH(), "0");
}

void menu(WINDOW *win, int xMax, int yMax) {
    int x, y;
    int c = 0;
	int i = 0;
    char list[3][9] = {"NEW GAME", "HELP", "QUIT"};
    char item[9];

    for (int t = 0; t < 3; t++) {
        x = xMax / 2;
        y = yMax / 2;
        move(10, 10);
        printw("Rush-Type");
        if (t == 0)
            wattron(win, A_STANDOUT);  // highlights the first item.
        else
            wattroff(win, A_STANDOUT);
        sprintf(item, "%-7s", list[t]);
        mvwprintw(win, t + 1, 2, "%s", item);
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
		clear();
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

int main(void) {
    Player player(1, 1);
    Game game(player);
    initscr();
    noecho();
    cbreak();

	int start = getMilliCount();
	int milliSecondsElapsed;
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    WINDOW *win = newwin(yMax, xMax, 0, 0);
	nodelay(win, TRUE);

    box(win, 0, 0);
    keypad(win, true);
    curs_set(0);  // hides the default screen cursor.
    menu(win, xMax, yMax);
    
    // Call when game begins (STORYLINE)
    storylineBegin(win, xMax, yMax);
    // Call when player fails (STORYLINE)
    // storylineFail(win, xMax, yMax);

 	while(game.player.alive) {
		milliSecondsElapsed = getMilliSpan(start) / 1000; // grabs current time

		getmaxyx(stdscr, yMax, xMax);
		windowClean(win);
		mvwprintw(win, 0, xMax /2, "Time: %d", milliSecondsElapsed);
		
		playerUpdate(win, game.player);
        // game.displayPlayer(win, game.player);
		
		game.getAction(win, yMax, xMax);
		wrefresh(win);
        usleep(DELAY);
    }

    endwin();
}

// Game begin storyline
void storylineBegin(WINDOW *win, int xMax, int yMax){

    const char *text = "The Earth is in trouble...";
    const char *text2 = "Mark Zuckerburg and the Queen of England threaten to enslave the entire world..";
    const char *text3 = "As Elon's Prized Space car it is up to you to protect the people of Earth..";
    const char *text4 = "Stop the ever growing Lizzard threat and mighty Elon will love you forever..";
    const char *text5 = "Begin game?";

    mvwprintw(win, 1, xMax / 2 - 20, text);
    
    wrefresh(win);
    wgetch(win);

    mvwprintw(win, 2, xMax / 2 - 45, text2);
    wrefresh(win);
    wgetch(win);

    mvwprintw(win, 3, xMax / 2 - 42, text3);
    wrefresh(win);
    wgetch(win);

    mvwprintw(win, 4, xMax / 2 - 43, text4);
    wrefresh(win);
    wgetch(win);
    
    wclear(win);
    wrefresh(win);

    mvwprintw(win, 5, xMax / 2 - 15, text5);
    wrefresh(win);
    wgetch(win);
}
// Game fail storyline
void storylineFail(WINDOW *win, int xMax, int yMax){
    const char *textFail1 = "You have doomed us all";
    const char *textFail2 = "The Queen of england now rules over humanity with Mark Zuckerburg at her side..";
    const char *textFail3 = "Retry?";

    wclear(win);
    wrefresh(win);

    mvwprintw(win, 1, xMax / 2 - 15, textFail1);
    wrefresh(win);
    wgetch(win);

    mvwprintw(win, 2, xMax / 2 - 42, textFail2);
    wrefresh(win);
    wgetch(win);

    wclear(win);
    wrefresh(win);

    mvwprintw(win, 5, xMax / 2 - 15, textFail3);
    wrefresh(win);
    wgetch(win);
}