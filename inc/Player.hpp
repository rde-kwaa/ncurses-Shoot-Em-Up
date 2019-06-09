#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <ncurses.h>
#include "../inc/Entity.hpp"

class Game;

class Player : public Entity
{
	private:
		void immaFirinMahLazer(WINDOW *win, int v, int h, const char * lazor);

    public:
        Player(void);
        Player(int h, int v);
        ~Player();
        void moveUp(int maxV);
        void moveDown(int maxV);
        void moveLeft();
        void moveRight(int maxH);
        void display();
        void shoot(WINDOW *win, int maxH);
		bool alive;
		
        std::string _character;
};

#endif
