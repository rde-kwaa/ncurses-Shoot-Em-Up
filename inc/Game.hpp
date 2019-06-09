
#ifndef GAME_HPP
#define GAME_HPP

#define DELAY 20000
#define ENEMIES 1000
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
        Player      player;
        Enemy       enemies[ENEMIES];

        Game(void);
        Game(Player player);
        Game(Game const &obj);
        ~Game();
        Game        &operator=(Game const &obj);
        
        // Game functions
        void        displayPlayer(WINDOW *win, Player player);
        void        displayEnemy(WINDOW *win, Enemy &enemy, int secondsElapsed);
        void        generateEnemy(int h, int v, int id);

        // Setters
        void        setTermHeight(int termHeight);
        void        setTermWidth(int termWidth);
        void        setTermDimensions(int termHeight, int termWidth);
        
        // Getters
        int         getTermHeight();
        int         getTermWidth();

        // Window functions
        WINDOW      *createWindow(int height, int width, int coY, int coX);
        void        getAction(WINDOW *win, int termHeight, int termWidth);
        void        windowClean(WINDOW *win);
        void        menu(WINDOW *win, int winHeight, int winWidth);

        int         getMilliCount();
        int         getMilliSpan(int nStartTime);   

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
