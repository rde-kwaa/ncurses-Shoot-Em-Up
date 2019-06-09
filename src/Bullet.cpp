
#include "../inc/Player.hpp"
#include "../inc/Bullet.hpp"

Bullet::Bullet(int h, int v, std::string c):Entity(h,v){
    this->_character = c;
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
