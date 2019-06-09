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

void Player::moveUp(int maxV){
    this->_v--;
    if (this->_v < 1){
        setV(maxV - 2);
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

void Player::immaFirinMahLazer(WINDOW *win, int v, int h, const char * lazor) {
		mvwprintw(win, v, h, lazor);
}

void Player::shoot(WINDOW *win, int maxH){
	int currentV = this->getV();
	int currentH = this->getH();
	std::string str= "";
	
	int lazorLen = maxH - 5;

	for (int i = currentH; i < lazorLen; i++){
		str.append("=");
	}
	immaFirinMahLazer(win, currentV, currentH+1, str.c_str());
}
