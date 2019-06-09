#ifndef PLAYER_H
#define PLAYER_H

#include <ncurses.h>
#include "../inc/Entity.hpp"

class Player : public Entity {
   private:
    int _killscore;

   public:
    Player(int h, int v, std::string c);
    ~Player();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    int getMove(WINDOW *win, int vMax, int hMax);
    void setKillScore();
    void display();
    void shoot();
    bool alive;

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
