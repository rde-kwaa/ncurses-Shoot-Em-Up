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

    int     i = 0;
    srand(time(NULL));	
 	while(game.player.alive) {
		milliSecondsElapsed = game.getMilliSpan(start) / 1000; // grabs current time

		game.windowClean(win);
		getmaxyx(stdscr, yMax, xMax);
		mvwprintw(win, 0, xMax /2, "Time: %d", milliSecondsElapsed);
        if (i < 10 && milliSecondsElapsed % 10 == 0)
        {
            game.generateEnemy(10, 10, i);
            i++;
        }
        for (int j = 0; j < i; j++)
        {
            game.displayEnemy(win, game.enemies[j], milliSecondsElapsed);
        }
        game.displayPlayer(win, game.player);
		game.getAction(win, yMax, xMax);
		wrefresh(win);
        usleep(DELAY);
    }

    endwin();
}
