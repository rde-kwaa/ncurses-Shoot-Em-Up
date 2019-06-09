/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlowing <jlowing@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 01:04:00 by akay              #+#    #+#             */
/*   Updated: 2019/06/09 13:37:02 by jlowing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Game.hpp"
#include <iostream>

/* DEFAULT
   FUNCTIONS */
Game::Game(void)
{
    return ;
}

Game::Game(Player player)
{
    this->player = player;
}

Game::Game(Game const &obj)
{
    *this = obj;
}

Game    &Game::operator=(Game const &obj)
{
    (void)obj;
    return (*this);
}

Game::~Game()
{
    return ;
}




/* SETTER
   FUNCTIONS */
void    Game::setTermHeight(int termHeight)
{
    this->_termHeight = termHeight;
}

void    Game::setTermWidth(int termWidth)
{
    this->_termWidth = termWidth;
}

void    Game::setTermDimensions(int termHeight, int termWidth)
{
    setTermHeight(termHeight);
    setTermWidth(termWidth);
}

void	Game::setStartTime(int time) {
	this->startTime = time;
}

/* GETTER
   FUNCTIONS */
int     Game::getTermHeight()
{
    return (this->_termHeight);
}

int     Game::getTermWidth()
{
    return(this->_termWidth);
}

int		Game::getStartTime() {
	return(this->startTime);
}

WINDOW  *Game::createWindow(int height, int width, int coY, int coX)
{
    WINDOW  *win = newwin(height, width, coY, coX);
    box(win, 0 , 0);
    
    return (win);
}

void    Game::displayPlayer(WINDOW *win, Player player)
{
    mvwprintw(win, player.getV(), player.getH(), "0");
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
	if (startX <= 2){
		startX = xMax - 1;
	}
	if( startX > xMax - 147){
		yMax--;
	}
	if (i == xMax - 1) {i = 0;}
	mvwprintw(win, yMax - 10, startX, "                        .           .                  *                      /   \\              _/ \\       *    .                                ");
	mvwprintw(win, yMax - 9, startX, "        _    .  ,   .           .         _    .       .                  .--'\\/\\_ \\            /    \\  *    ___                                  ");
	mvwprintw(win, yMax - 8, startX, "    *  / \\_ *  / \\_      _  *        *   /\\'__      *                 *  / \\_    _/ ^      \\/\\'__        /\\/\\  /\\  __/   \\ *                      ");
	mvwprintw(win, yMax - 7, startX, "      /    \\  /    \\,   ((        .    _/  /  \\  *'.                    /    \\  /    .'   _/  /  \\  *' /    \\/  \\/ .`'\\_/\\   .                    ");
	mvwprintw(win, yMax - 6, startX, " .   /\\/\\  /\\/ :' __ \\_  `          _^/  ^/    `--.  .                 /\\/\\  /\\/ :' __  ^/  ^/    `--./.'  ^  `-.\\ _    _:\\ _                     ");
	mvwprintw(win, yMax - 5, startX, "    /    \\/  \\  _/  \\-'\\      *    /.' ^_   \\_   .'\\             *    /    \\/  \\  _/  \\-' __/.' ^ _   \\_   .'\\   _/ \\ .  __/ \\                    ");
	mvwprintw(win, yMax - 4, startX, "  /\\  .-   `. \\/     \\ /==~=-=~=-=-;.  _/ \\ -. `_/   \\               /\\  .-   `. \\/     \\ / -.   _/ \\ -. `_/   \\ /    `._/  ^  \\                  ");
	mvwprintw(win, yMax - 3, startX, " /  `-.__ ^   / .-'.--\\ =-=~_=-=~=^/  _ `--./ .-'  `- \\             / `-.__ ^   / .-'.--'    . /    `--./ .-'  `-.  `-. `.  -  `.                 ");
	mvwprintw(win, yMax - 2, startX, "/        `.  / /       `.~-^=-=~=^=.-'      '-._ `._   \\           /      `.  / /      `-.   /  .-'   / .   .'   \\    \\  \\  .-   \\                ");
}

void    Game::windowClean(WINDOW *win) {
	werase(win);
	makeScenery(win, this->getMilliSpan(this->getStartTime()));
	box(win, 0, 0);
}

void    Game::menu(WINDOW *win, int yMax, int xMax) {
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
    }
    werase(win);
}

int     Game::getMilliCount(){
	timeb tb;
	ftime(&tb);
	int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
	return nCount;
}

int     Game::getMilliSpan(int nTimeStart){
	int nSpan = getMilliCount() - nTimeStart;
	if(nSpan < 0)
		nSpan += 0x100000 * 1000;
	return nSpan;
}

void    Game::storylineBegin(WINDOW *win, int maxH){

    const char *text1 = "The Earth is in trouble...";
    const char *text2 = "Mark Zuckerburg and the Queen of England threaten to enslave the entire world..";
    const char *text3 = "As Elon's Prized Space car it is up to you to protect the people of Earth..";
    const char *text4 = "Stop the ever growing Lizzard threat and mighty Elon will love you forever..";
    const char *text5 = "Begin game?";
    
    wclear(win);
    wrefresh(win);
    
    getch();
    wrefresh(win);

    mvwprintw(win, 1, maxH / 2 - 20, text1);
    wrefresh(win);
    getch();    

    mvwprintw(win, 2, maxH / 2 - 45, text2);
    wrefresh(win);
    getch();    

    mvwprintw(win, 3, maxH / 2 - 42, text3);
    wrefresh(win);
    getch();

    mvwprintw(win, 4, maxH / 2 - 43, text4);
    wrefresh(win);
    getch();    
    
    wclear(win);
    wrefresh(win);

    mvwprintw(win, 5, maxH / 2 - 15, text5);
    wrefresh(win);
    getch();
}

void    Game::storylineFail(WINDOW *win, int maxH){
    const char *textFail1 = "You have doomed us all";
    const char *textFail2 = "The Queen of england now rules over humanity with Mark Zuckerburg at her side..";
    const char *textFail3 = "Retry?";

    wclear(win);
    wrefresh(win);

    mvwprintw(win, 1, maxH / 2 - 15, textFail1);
    wrefresh(win);
    getch();    

    mvwprintw(win, 2, maxH / 2 - 42, textFail2);
    wrefresh(win);
    getch();


    wclear(win);
    wrefresh(win);

    mvwprintw(win, 5, maxH / 2 - 15, textFail3);
    wrefresh(win);
    getch();
}
