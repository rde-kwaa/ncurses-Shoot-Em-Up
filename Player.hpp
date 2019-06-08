#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <ncurses.h>
#include "Entity.hpp"

class Player : public Entity
{

    public:
        Player(int h, int v, std::string c);
        ~Player();
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
        int  getMove(WINDOW *win, int vMax, int hMax);
        void display();
        void shoot();
		bool alive;
		
        std::string c;
};

#endif