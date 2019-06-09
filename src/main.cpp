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

	
    
    getmaxyx(stdscr, yMax, xMax);
    
    WINDOW *win = game.createWindow(yMax, xMax, 0, 0);
	nodelay(win, TRUE);

    box(win, 0, 0);
    keypad(win, true);
    curs_set(0);  // hides the default screen cursor.

    game.setTermDimensions(yMax, xMax);
	
	// Menu/game music start
	//  Comment out to turn off music
	game.menu_sound();
    
	game.menu(win, yMax, xMax);

    int     i = 0;
    int     k = 0;
	game.storylineBegin(win, xMax);
	int start = game.getMilliCount();
	int milliSecondsElapsed;
    srand(time(NULL));	
 	while(game.player.alive) {
		milliSecondsElapsed = game.getMilliSpan(start) / 1000; // grabs current time

		game.windowClean(win);
		getmaxyx(stdscr, yMax, xMax);
		mvwprintw(win, 0, xMax /2, "score: %d	Time: %d", game.player.getScore(),milliSecondsElapsed);
        if (i < ENEMIES && k % 10 == 0)
        {
            game.generateEnemy(10, 10, i);
            i++;
        }
        game.displayPlayer(win, game.player);
        for (int j = 0; j < i; j++)
        {
            game.displayEnemy(win, game.enemies[j], milliSecondsElapsed);
        }
        for (int m = 0; m < i; m++)
        {
            if ((game.player.getH() == game.enemies[m].getH()) && (game.player.getV()) == game.enemies[m].getV())
            {
                // Call when player fails (STORYLINE)
                game.storylineFail(win, xMax);
                game.game_Over();
                wclear(win);
                endwin();
                return (0);
            }
        }
		game.getAction(win, yMax, xMax);
		wrefresh(win);
        usleep(DELAY);
        k++;
    }

    endwin();
    return (0);
}
