#include "../inc/Player.hpp"
#include "../inc/Bullet.hpp"

Player::Player(void)
{
    return ;
}

Player::Player(int h, int v) : Entity(h, v) {
    this->_character = "0";
	this->_speed = 1;
	this->alive = true;
    // getmaxyx(this->win, this->yMax, this->xMax);
    
}

Player::~Player(){

}

void Player::moveUp(){
    this->_v--;
    if (this->_v < 1){
        setV(1);
    }
}

void Player::moveDown(int maxV){
    this->_v++;
    if (this->_v > maxV - 2){
        this->_v = 1;
    }
}

void Player::moveLeft(){
    this->_h--;
    if (this->_h < 1){
        setH(1);
    }
}

void Player::moveRight(int maxH){
    this->_h++;
    if (this->_h > maxH - 2){
        setH(maxH - 2);
    }
}

void Player::shoot(){
    Bullet  playerBullet(this->_h+1, this->_v, ".");
    playerBullet.player = true;
}

// int Player::getMove(WINDOW *win, int yMax, int xMax){
// 	this->_maxH = xMax;
// 	this->_maxV = yMax;
	
//     int move = wgetch(win);
//     switch(move){
//         case KEY_UP:{
//             moveUp();
// 			break;
// 		}
//         case KEY_DOWN:{
//             moveDown();
// 			break;
// 		}
//         case KEY_LEFT:{
//             moveLeft();
// 			break;
// 		}
//         case KEY_RIGHT:{
//             moveRight();
// 			break;	
// 		}
//         case KEY_F0:{
//             shoot();
//             break;
//         }
//         default:
//             break;
//     }
//     return move;
// }
