// #include "../inc/Entity.hpp"
#include "../inc/Game.hpp"
#include "../inc/Player.hpp"

int main(void) {
	Player player(1, 1);
	Game game(player);
	int yMax, xMax;
	int menuNumber;
	int menu = 1;

	initscr();
    noecho();
    cbreak();

	int start = game.getMilliCount();
	game.setStartTime(start);
	int milliSecondsElapsed;

    getmaxyx(stdscr, yMax, xMax);

    WINDOW *win = game.createWindow(yMax, xMax, 0, 0);
	nodelay(win, TRUE);

	box(win, 0, 0);
	keypad(win, true);
	curs_set(0);  // hides the default screen cursor.
	while (menu) {
		menuNumber = game.menu(win, yMax, xMax);
		game.windowClean(win);
		wrefresh(win);
		switch (menuNumber) {
			case 0:
				//Play game
				menu = 0;
				break;
			case 1:
				//Help menu
				game.help(win, yMax);
				game.windowClean(win);
				wrefresh(win);
				break;
			case 2:
				//Quit
				game.windowClean(win);
				wrefresh(win);
				return 0;
			default:
				break;
		}
	}
	game.setTermDimensions(yMax, xMax);

	// Menu/game music start
	//  Comment out to turn off music
	pid_t pid = game.menu_sound();

    int     i = 0;
    int     k = 0;
	game.storylineBegin(win, xMax);
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
		game.enemyAttacks(win, game.player);
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
				kill(pid, SIGKILL);
                wclear(win);
                endwin();
                return (0);
            }
        }
		game.getAction(win, yMax, xMax, pid);
		wrefresh(win);
        usleep(DELAY);
        k++;
    }
	kill(pid, SIGKILL);

    endwin();
    return (0);
}

