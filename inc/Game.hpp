#ifndef GAME_HPP
#define GAME_HPP

#define DELAY 20000
#include <ncurses.h>
#include <sys/timeb.h>
#include <unistd.h>
#include <cstdlib>
#include <iostream>
#include "../inc/Player.hpp"

class Game {
   public:
	Player player;

	Game(void);
	Game(Player player);
	Game(Game const &obj);
	~Game();
	Game &operator=(Game const &obj);

	// Window functions
	WINDOW *createWindow(int height, int width, int coY, int coX);
	void getAction(WINDOW *win, int termHeight, int termWidth);
	void windowClean(WINDOW *win);
	int menu(WINDOW *win, int winHeight, int winWidth);
	int help(WINDOW *win, int winHeight);

	// Game functions
	void displayPlayer(WINDOW *win, Player player);

	// Setters
	void setTermHeight(int termHeight);
	void setTermWidth(int termWidth);
	void setTermDimensions(int termHeight, int termWidth);

	// Getters
	int getTermHeight();
	int getTermWidth();
	int getMilliCount();
	int getMilliSpan(int nStartTime);

	// Storyline
	void        storylineBegin(WINDOW *win, int maxH);
	void        storylineFail(WINDOW *win, int maxH);

	// Sound
	void        menu_sound(void);
	void        laser_sound(void);
	void        boom(void);
	void        game_Over(void);

	private:
		int         _termHeight;
		int         _termWidth;
};

#endif
