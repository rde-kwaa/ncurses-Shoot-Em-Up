#include "../inc/Game.hpp"
#include <iostream>

/* DEFAULT
   FUNCTIONS */
Game::Game(void) {
	return;
}

Game::Game(Player player) {
	this->player = player;
}

Game::Game(Game const &obj) {
	*this = obj;
}

Game &Game::operator=(Game const &obj) {
	(void)obj;
	return (*this);
}

Game::~Game() {
	return;
}

/* SETTER
   FUNCTIONS */
void Game::setTermHeight(int termHeight) {
	this->_termHeight = termHeight;
}

void Game::setTermWidth(int termWidth) {
	this->_termWidth = termWidth;
}

void Game::setTermDimensions(int termHeight, int termWidth) {
	setTermHeight(termHeight);
	setTermWidth(termWidth);
}

void	Game::setStartTime(int time) {
	this->startTime = time;
}

/* GETTER
   FUNCTIONS */
int Game::getTermHeight() {
	return (this->_termHeight);
}

int Game::getTermWidth() {
	return (this->_termWidth);
}

int		Game::getStartTime() {
	return(this->startTime);
}

WINDOW  *Game::createWindow(int height, int width, int coY, int coX)
{
	start_color();
    WINDOW  *win = newwin(height, width, coY, coX);
    box(win, 0 , 0);
    
    return (win);
}

void    Game::displayPlayer(WINDOW *win, Player player)
{
	init_pair(3, COLOR_GREEN, 0);
	wattron(win, COLOR_PAIR(3));
	const char * playerShip = this->player._character.c_str();
    mvwprintw(win, player.getV(), player.getH(), playerShip);
	wattroff(win, COLOR_PAIR(3));
}

void   Game::displayEnemy(WINDOW *win, Enemy &enemy, int i)
{
    (void)i;
    enemy.setH(enemy.getH() - 1);
    if (enemy.getH() < 1)
    {
        enemy.resetEnemy(this->getTermWidth(), this->getTermHeight() - 5);
    }
	init_pair(2, COLOR_RED, 0);
	wattron(win, COLOR_PAIR(2));
    mvwprintw(win, enemy.getV(), enemy.getH(), "X");
	wattroff(win, COLOR_PAIR(2));

}


void        Game::getAction(WINDOW *win, int termHeight, int termWidth)
{
	int move = wgetch(win);
	switch(move)
	{
		case KEY_UP:
			this->player.moveUp(termHeight);
			break;
		case KEY_DOWN:
			this->player.moveDown(termHeight);
			break;
		case KEY_LEFT:
			this->player.moveLeft();
			break;
		case KEY_RIGHT:
			this->player.moveRight(termWidth);
			break;
		case ' ':
			this->player.shoot(win, termWidth, termHeight, this->enemies);
			break;
		case 27:
			windowClean(win);
			wrefresh(win);
			exit(0);
		break;
		default:
			break;
	}
}


void	Game::makeScenery(WINDOW *win, int time) {
	static int i;
	(void)time;
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);
	int startX = xMax - i++;
	if (i == xMax - 1) {i = 0;}
	init_pair(1, 4, 0);
	wattron(win, COLOR_PAIR(1));
	mvwprintw(win, yMax - 10, startX, "                        .           .                  *                      /   \\              _/ \\       *    .                                ");
	mvwprintw(win, yMax - 9, startX, "        _    .  ,   .           .         _    .       .                  .--'\\/\\_ \\            /    \\  *    ___                                  ");
	mvwprintw(win, yMax - 8, startX, "    *  / \\_ *  / \\_      _  *        *   /\\'__      *                 *  / \\_    _/ ^      \\/\\'__        /\\/\\  /\\  __/   \\ *                      ");
	mvwprintw(win, yMax - 7, startX, "      /    \\  /    \\,   ((        .    _/  /  \\  *'.                    /    \\  /    .'   _/  /  \\  *' /    \\/  \\/ .`'\\_/\\   .                    ");
	mvwprintw(win, yMax - 6, startX, " .   /\\/\\  /\\/ :' __ \\_  `          _^/  ^/    `--.  .                 /\\/\\  /\\/ :' __  ^/  ^/    `--./.'  ^  `-.\\ _    _:\\ _                     ");
	mvwprintw(win, yMax - 5, startX, "    /    \\/  \\  _/  \\-'\\      *    /.' ^_   \\_   .'\\             *    /    \\/  \\  _/  \\-' __/.' ^ _   \\_   .'\\   _/ \\ .  __/ \\                    ");
	mvwprintw(win, yMax - 4, startX, "  /\\  .-   `. \\/     \\ /==~=-=~=-=-;.  _/ \\ -. `_/   \\               /\\  .-   `. \\/     \\ / -.   _/ \\ -. `_/   \\ /    `._/  ^  \\                  ");
	mvwprintw(win, yMax - 3, startX, " /  `-.__ ^   / .-'.--\\ =-=~_=-=~=^/  _ `--./ .-'  `- \\             / `-.__ ^   / .-'.--'    . /    `--./ .-'  `-.  `-. `.  -  `.                 ");
	mvwprintw(win, yMax - 2, startX, "/        `.  / /       `.~-^=-=~=^=.-'      '-._ `._   \\           /      `.  / /      `-.   /  .-'   / .   .'   \\    \\  \\  .-   \\                ");
	wattroff(win, COLOR_PAIR(1));

}

void    Game::windowClean(WINDOW *win) {
	werase(win);
	makeScenery(win, this->getMilliSpan(this->getStartTime()));
	box(win, 0, 0);
		
}

int Game::menu(WINDOW *win, int yMax, int xMax) {
	int xCen = xMax / 2 - 8;
	int yCen = yMax / 2 - 2;
	int item;
	int highlight = 0;
	int ws = 0;
	std::string items[3] = {"NEW GAME", "HELP", "QUIT"};
	std::string s;

	while (1) {
		mvwprintw(win, yCen - 2, xCen + 4, "|FT_RETRO|");
		for (int i = 0; i < 3; i++) {
			if (i == highlight)
				wattron(win, A_STANDOUT);
			s = items[i].c_str();
			(strlen(s.c_str()) > 5) ? ws = 4 : ws = 6;
			// print at centered coordinate. c_str is to cast as it only takes char *.
			mvwprintw(win, i + yCen + 1, xCen + 1, "%*s%*s",
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
		if (item == 10) {
			switch (highlight) {
				case 0:
					return 0;
				case 1:
					return 1;
				case 2:
					return 2;
				default:
					break;
			}
		}
	}
}

int Game::help(WINDOW *win, int yMax) {
	int ch;
	std::string back = "BACK";
	std::string instructs[15] = {
		"OBJECTIVE:",
		"Shoot down your enemies that will appear on the right of the screen, but don't collide with them!",
		"Each enemy that you eliminate will add to your killscore.",
		"Get the highest killscore possible, and most importantly, have FUN!!!",
		" ",
		"MOVEMENT:",
		"UP ARROW - Go Up...",
		"DOWN ARROW - Go Down...",
		"LEFT ARROW - Go Left...",
		"RIGHT ARROW - Go Right...",
		" ",
		"ACTIONS:",
		"SPACEBAR - Fire",
		"",
		"EXIT - ESC x 2"};

	while (1) {
		mvwprintw(win, 2, 3, "HELP:");
		for (int i = 0; i < 15; i++) {
			mvwprintw(win, 4 + i, 3, "%s", instructs[i].c_str());
		}
		wattron(win, A_STANDOUT);
		curs_set(1);

		mvwprintw(win, yMax - 3, 3, "%s", back.c_str());
		curs_set(0);
		wattroff(win, A_STANDOUT);
		ch = wgetch(win);
		wrefresh(win);
		if (ch == 10) {
			return 1;
		}
	}
}

int Game::getMilliCount() {
	timeb tb;
	ftime(&tb);
	int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
	return nCount;
}

int Game::getMilliSpan(int nTimeStart) {
	int nSpan = getMilliCount() - nTimeStart;
	if (nSpan < 0)
		nSpan += 0x100000 * 1000;
	return nSpan;
}
void    Game::storylineBegin(WINDOW *win, int maxH){
std::string texts[5] = {
		"The Earth is in trouble...",
		"Mark Zuckerburg and the Queen of England threaten to enslave the entire world..",
		"As Elon's Prized Space car it is up to you to protect the people of Earth..",
		"Stop the ever growing Lizzard threat and mighty Elon will love you forever..",
		"Begin Game?"};
int cenX[5] = {20, 45, 42, 43, 15};

    wclear(win);
    wrefresh(win);
	getch();

	for (int i=0; i<5; i++){
		mvwprintw(win, 1 + i, maxH / 2 - cenX[i], texts[i].c_str());
    	wrefresh(win);
    	getch();
	}
}

void    Game::storylineFail(WINDOW *win, int maxH){
	std::string texts[2] = {
		"You have doomed us all",
		"The Queen of england now rules over humanity with Mark Zuckerburg at her side.."};
	int cenX[2] = {15, 42};

    wclear(win);
    wrefresh(win);

	for (int i=0; i<2; i++){
		mvwprintw(win, 1 + i, maxH / 2 - cenX[i], texts[i].c_str());
    	wrefresh(win);
    	getch();
	}
	wclear(win);
    wrefresh(win);
}
#include <signal.h>
void        Game::menu_sound(void)
{

    pid_t pid = fork();
    if (!pid)
    {
        execlp("afplay", "afplay", "./res/BeachLasagne.mp3", NULL);
		exit(0);
    }
}

void        Game::boom(void)
{
    pid_t pid = fork();
    if (!pid)
    {
        execlp("afplay", "afplay", "./res/Boom.mp3", NULL);
        exit(0);
    }
}

void        Game::game_Over(void)
{
    pid_t pid = fork();
    if (!pid)
    {
        execlp("afplay", "afplay", "./res/gameovervoice.mp3", NULL);
        exit(0);
    }
}


void    Game::generateEnemy(int h, int v, int id)
{
    this->enemies[id].setH(h);
    this->enemies[id].setV(v);
    this->enemies[id].randomStart(this->getTermWidth(), this->getTermHeight() - 2);
}
