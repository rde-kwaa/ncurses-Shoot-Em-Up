#ifndef BULLET_H
#define BULLET_H
#include <iostream>

class Bullet : public Entity
{
    public:
        Bullet(int h, int v, std::string c);
        ~Bullet();

        void moveLeft();
        void moveRight();
        void display();

        std::string c;

        bool player;
};
#endif