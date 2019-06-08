#include <iostream>

class Bullet
{
    public:
        Bullet(int h, int v, std::string c);
        ~Bullet();

        void moveLeft();
        void moveRight();
        void display();

        bool player;
}
