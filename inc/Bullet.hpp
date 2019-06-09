#ifndef BULLET_H
#define BULLET_H
#include <iostream>
#include "Entity.hpp"

# include "../inc/Entity.hpp"

class Bullet : public Entity
{
    public:
        Bullet(int h, int v, std::string c);
        ~Bullet();
        // void updatePosition();
        std::string c;

        bool player;
};
#endif
