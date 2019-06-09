#include "../inc/Player.hpp"
#include "../inc/Bullet.hpp"

#define ENEMIES 100

Player::Player(void)
{
	return ;
}

Player::Player(int h, int v) : Entity(h, v) {
    this->_character = "<)==>";
	this->_hp = 3;
	this->alive = true;
	this->_score = 0;
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

int Player::getScore(void){
	return(this->_score);
}

void Player::setScore(int n){
	this->_score = n;
}

void Player::immaFirinMahLazer(WINDOW *win, int v, int h, const char * lazor) {
	init_pair(4, COLOR_CYAN, 0);
	wattron(win, COLOR_PAIR(4));
	mvwprintw(win, v, h, lazor);
	wattroff(win, COLOR_PAIR(4));

}

std::string CreateLazer(int lazorLen, int currentH){
	std::string str= "";
	for (int i = currentH; i < lazorLen; i++){
		str.append("=");
	}
	return (str);
}
void Player::die() {
	this->alive = false;
}


void laser_sound(void)
{
    pid_t pid = fork();
    if (!pid)
    {
        execlp("afplay", "afplay", "./res/pew.mp3", NULL);
        exit(0);
    }
}


void Player::shoot(WINDOW *win, int maxH, int maxV, Enemy enemies[ENEMIES]){
	int currentV = this->getV();
	int currentH = this->getH();
	int tmpEnemy = -1;
	int tmpEnemyH = maxH;
	std::string lazer;
	int lazorLen = maxH - 10;
	for (int i = 0; i <= ENEMIES; i++){

		if(enemies[i].getV() == currentV && (enemies[i].getH() <= maxH - 5) && (enemies[i].getH() > this->getH())  && (enemies[i].getH() < tmpEnemyH) ){
			tmpEnemyH = enemies[i].getH();
			tmpEnemy = i;
		}
	}
	if (tmpEnemy >= 0){
		lazorLen = enemies[tmpEnemy].getH();
		lazer = CreateLazer(lazorLen, currentH);
		enemies[tmpEnemy].resetEnemy(maxH,maxV);
		this->setScore(this->getScore() + 1);
	} else {
		lazer = CreateLazer(lazorLen, currentH);

	}
	laser_sound();
	immaFirinMahLazer(win, currentV, currentH+1, (const char *)lazer.c_str());
}
