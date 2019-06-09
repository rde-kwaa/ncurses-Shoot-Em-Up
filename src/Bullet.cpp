
#include "../inc/Player.hpp"
#include "../inc/Bullet.hpp"

Bullet::Bullet(int x, int y, std::string c){
	this->_h  = x;
	this->_v = y;
	this->_character = c;
	this->_speed = 1;
	this->player = false;
}
 Bullet::~Bullet(){
 }

// void    Bullet::updatePosition(){
//     if (this->_h == this->_maxH){
//         this->_h = -1;
//         this->_v = -1;
//     }
// }
