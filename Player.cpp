#include "Player.hpp"

Player::Player(int x, int y, std::string c){
    this->h  = x;
    this->v = y;
    this->c = c;
	this->speed = 1;
	this->alive = true;
    // getmaxyx(this->win, this->yMax, this->xMax);
    
}

Player::~Player(){

}

void Player::moveUp(){
    this->v--;
    if (this->v < 1){
        this->v = this->vMax - 2;
    }
}

void Player::moveDown(){
    this->v++;
    if (this->v > vMax - 2){
        this->v = 1;
    }
}

void Player::moveLeft(){
    this->h--;
    if (this->h < 1){
        this->h = this->hMax - 2;
    }
}

void Player::moveRight(){
    this->h++;
    if (this->h > this->hMax - 2){
        this->h = 1;
    }
}

void display(){
    
}

int Player::getMove(WINDOW *win, int yMax, int xMax){
	this->hMax = xMax;
	this->vMax = yMax;
	
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