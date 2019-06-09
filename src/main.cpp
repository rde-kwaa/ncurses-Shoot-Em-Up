// #include "../inc/Entity.hpp"
#include "../inc/Game.hpp"
#include "../inc/Player.hpp"

int main(void) {
	Player player(1, 1);
	Game game(player);
	int yMax, xMax;
	int menu = 1;

	initscr();
	noecho();
	cbreak();

	int start = game.getMilliCount();
	int milliSecondsElapsed;
	int menuNumber;

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

	while (game.player.alive) {
		milliSecondsElapsed = game.getMilliSpan(start) / 1000;  // grabs current time

    // Call when game begins (STORYLINE)
    game.storylineBegin(win, xMax);

 	while(game.player.alive) {
		milliSecondsElapsed = game.getMilliSpan(start) / 1000; // grabs current time

		getmaxyx(stdscr, yMax, xMax);
		game.windowClean(win);
		mvwprintw(win, 0, xMax / 2, "Time: %d", milliSecondsElapsed);
		game.displayPlayer(win, game.player);
		game.getAction(win, yMax, xMax);
		wrefresh(win);
        usleep(DELAY);
    }
    // Call when player fails (STORYLINE)
    game.storylineFail(win, xMax);

	endwin();
}
