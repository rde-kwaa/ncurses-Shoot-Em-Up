// #include "../inc/Entity.hpp"
#include "../inc/Player.hpp"
#include "../inc/Game.hpp"

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
    
    WINDOW *win = game.createWindow(yMax, xMax, 0, 0);
	nodelay(win, TRUE);

    box(win, 0, 0);
    keypad(win, true);
    curs_set(0);  // hides the default screen cursor.

    game.setTermDimensions(yMax, xMax);
    game.menu(win, yMax, xMax);

    // Call when game begins (STORYLINE)
    game.storylineBegin(win, xMax);

 	while(game.player.alive) {
		milliSecondsElapsed = game.getMilliSpan(start) / 1000; // grabs current time

		getmaxyx(stdscr, yMax, xMax);
		game.windowClean(win);
		mvwprintw(win, 0, xMax /2, "Time: %d", milliSecondsElapsed);
        game.displayPlayer(win, game.player);
		game.getAction(win, yMax, xMax);
		wrefresh(win);
        usleep(DELAY);
    }
    // Call when player fails (STORYLINE)
    game.storylineFail(win, xMax);

    endwin();
}
