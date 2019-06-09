#ifndef PLAYER_H
#define PLAYER_H

#include <ncurses.h>
#include <iostream>
#include <ncurses.h>
#include "../inc/Entity.hpp"

class Player : public Entity {
   private:
    int _killscore;

    public:
        Player(void);
        Player(int h, int v);
        ~Player();
        void moveUp(int maxV);
        void moveDown(int maxV);
        void moveLeft();
        void moveRight(int maxH);
        void display();
        void shoot();
		bool alive;
		
        std::string _character;
};

#endif
