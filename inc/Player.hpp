#ifndef PLAYER_H
#define PLAYER_H

#include <signal.h>
#include <unistd.h>
#include <iostream>
#include <ncurses.h>
#include "../inc/Entity.hpp"
#include "../inc/Enemy.hpp"

class Game;

class Player : public Entity
{
	private:
		void immaFirinMahLazer(WINDOW *win, int v, int h, const char * lazor);
		int _score;

    public:
        Player(void);
        Player(int h, int v);
        ~Player();
        void moveUp(int maxV);
        void moveDown(int maxV);
        void moveLeft();
        void moveRight(int maxH);
        void display();
        void shoot(WINDOW *win, int maxH, int maxV, Enemy enemies[10]);
		bool alive;
		int getScore(void);
		void setScore(int n);
		void die();
        std::string _character;
};

#endif
