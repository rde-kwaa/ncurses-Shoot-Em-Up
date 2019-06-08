
#include "Player.hpp"
#include "Bullet.hpp"

Bullet::Bullet(int x, int y, std::string c){
    this->h  = x;
    this->v = y;
    this->c = c;
	this->speed = 1;
	this->player = false;
}