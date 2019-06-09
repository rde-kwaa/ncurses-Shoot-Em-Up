// #include "../inc/Entity.hpp"
#include "../inc/Player.hpp"
#include "../inc/Game.hpp"

#define DELAY 20000

void playerUpdate(WINDOW *win, Player playerOne){
	mvwprintw(win, playerOne.getV(), playerOne.getH(), "0");
}

int main(void) {
    Player player(1, 1);
    Game game(player);
    int yMax, xMax;
    
    initscr();
    noecho();
    cbreak();

	int start = game.getMilliCount();
	int milliSecondsElapsed;
    
    getmaxyx(stdscr, yMax, xMax);
    yMax -= 10;
    xMax -= 10;
    
    WINDOW *win = game.createWindow(yMax, xMax, 0, 0);
	nodelay(win, TRUE);

    box(win, 0, 0);
    keypad(win, true);
    curs_set(0);  // hides the default screen cursor.

    game.setTermDimensions(yMax, xMax);
    game.menu(win, yMax, xMax);

 	while(game.player.alive) {
		milliSecondsElapsed = game.getMilliSpan(start) / 1000; // grabs current time

		getmaxyx(stdscr, yMax, xMax);
		yMax -=10;
		xMax -=10;
		clear();
		game.windowClean(win);
		mvwprintw(win, 0, xMax /2, "Time: %d", milliSecondsElapsed);
        game.displayPlayer(win, game.player);
		refresh();
		game.getAction(win, yMax, xMax);
		wrefresh(win);
        usleep(DELAY);
    }

    endwin();
}
