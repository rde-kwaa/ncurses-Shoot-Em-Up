#include <ncurses.h>
#include <unistd.h>
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
    mvwprintw(win, playerOne.v, playerOne.h, "0");
}

void objectUpdate(WINDOW *win, std::list<Entity> &listOfPlayer, int yMax, int xMax) {
    std::list<Entity>::iterator it = listOfPlayer.begin();
    it = listOfPlayer.begin();
    int next_x;
    // TODO -- loop list

    next_x = it->h + it->speed;

    if (next_x >= xMax || next_x < 0) {
        it->speed *= -1;
    } else {
        it->h += it->speed;
    }
    mvwprintw(win, 5 + 2, it->h, "0");
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

int main(int argc, char *argv[]) {
    initscr();
    noecho();
    cbreak();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    yMax -= 10;
    xMax -= 10;
    WINDOW *win = newwin(yMax, xMax, 0, 0);
    box(win, 0, 0);
    keypad(win, true);
    curs_set(0);  // hides the default screen cursor.
    menu(win, xMax, yMax);

    Player playerOne(1, 1, "0");

    while (playerOne.alive) {
        getmaxyx(stdscr, yMax, xMax);
        yMax -= 10;
        xMax -= 10;
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
