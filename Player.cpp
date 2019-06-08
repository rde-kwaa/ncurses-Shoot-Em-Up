#include "Player.hpp"

Player::Player(int x, int y, std::string c){
    this->_h  = x;
    this->_v = y;
    this->_character = c;
	this->_speed = 1;
	this->_alive = true;
    // getmaxyx(this->win, this->yMax, this->xMax);
    
}

Player::~Player(){

}

void Player::moveUp(){
    this->_v--;
    if (this->_v < 1){
        this->_v = this->_maxV - 2;
    }
}

void Player::moveDown(){
    this->_v++;
    if (this->_v > _maxV - 2){
        this->_v = 1;
    }
}

void Player::moveLeft(){
    this->_h--;
    if (this->_h < 1){
        this->_h = this->_maxH - 2;
    }
}

void Player::moveRight(){
    this->_h++;
    if (this->_h > this->_maxH - 2){
        this->_h = 1;
    }
}

void display(){
    
}

int Player::getMove(WINDOW *win, int yMax, int xMax){
	this->_maxH = xMax;
	this->_maxV = yMax;
	
    int move = wgetch(win);
    switch(move){
        case KEY_UP:{
            moveUp();
			break;
		}
        case KEY_DOWN:{
            moveDown();
			break;
		}
        case KEY_LEFT:{
            moveLeft();
			break;
		}
        case KEY_RIGHT:{
            moveRight();
			break;	
		}		
        default:
            break;
    }
    return move;
}