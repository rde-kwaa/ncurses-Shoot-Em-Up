#ifndef GAME_HPP
#define GAME_HPP

#define DELAY 20000
#define ENEMIES 100
#include <ncurses.h>
#include "../inc/Player.hpp"
#include "../inc/Enemy.hpp"
#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/timeb.h>

class Game
{
	public:
		Player		player;
		Enemy		enemies[ENEMIES];

		Game(void);
		Game(Player player);
		Game(Game const &obj);
		~Game();
		Game		&operator=(Game const &obj);

		// Game functions
		void		displayPlayer(WINDOW *win, Player player);
		void		displayEnemy(WINDOW *win, Enemy &enemy, int secondsElapsed);
		void		generateEnemy(int h, int v, int id);
		void		enemyAttacks(WINDOW *win, Player player);

		// Setters
		void		setTermHeight(int termHeight);
		void		setTermWidth(int termWidth);
		void		setTermDimensions(int termHeight, int termWidth);
		void		setStartTime(int startTime);

        // Getters
        int         getTermHeight();
        int         getTermWidth();
		int			getStartTime();

        // Window functions
        WINDOW      *createWindow(int height, int width, int coY, int coX);
        void        getAction(WINDOW *win, int termHeight, int termWidth, pid_t pid);
        void        windowClean(WINDOW *win);
        int        menu(WINDOW *win, int winHeight, int winWidth);
		void		makeScenery(WINDOW *win, int time);
		int			help(WINDOW *win, int yMax);

		int			getMilliCount();
		int			getMilliSpan(int nStartTime);

		// Storyline
		void		storylineBegin(WINDOW *win, int maxH);
		void		storylineFail(WINDOW *win, int maxH);

		// Sound
		pid_t       menu_sound(void);
		void        laser_sound(void);
		void        boom(void);
		void        game_Over(void);

	private:
		int			_termHeight;
		int			_termWidth;
		unsigned int startTime;
};

#endif
