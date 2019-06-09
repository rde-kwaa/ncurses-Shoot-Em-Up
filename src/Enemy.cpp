#include "../inc/Enemy.hpp"

Enemy::Enemy(void)
{
	this->_phase = 0;
	return ;
}

void Enemy::randomStart(int maxH, int maxV) {
	int r = rand() % 10;
	if (r % 2)
		setType("small");
	else
		setType("big");
	this->_h = maxH - 5;
	int iRand = std::rand() % maxV;
	if (iRand == -1 || iRand == 0)
	{
		iRand -= 2;
	}
	this->_v = iRand;
}

Enemy::Enemy(int h, int v):Entity(h,v){
	//this->_character = "<)}";
	this->_h = h;
	this->_v = v;
	this->_phase = 0;
	// _randomStart();
	return ;
}

Enemy::Enemy(const Enemy &Enemy){
	*this = Enemy;
	return ;
}
Enemy::~Enemy(void){
	// std::cout << "Enemy destroyed\n";
	return ;
}

Enemy &Enemy::operator=(const Enemy &enemy){
	this->_character = enemy._character;
	this->_h = enemy._h;
	this->_v = enemy._v;
	this->_speed = enemy._speed;
	this->_phase = 0;
	return (*this);
}

void			Enemy::setSize(int n) {
	this->_size = n;
}

void			Enemy::setType(std::string type) {
	this->_type = type;
}

void			Enemy::setPhase(int n) {
	this->_phase = n;
}

int				Enemy::getSize(void) {
	return (this->_size);
}

std::string		Enemy::getType(void) {
	return (this->_type);
}

int				Enemy::getPhase(void) {
	return (this->_phase);
}

void 			Enemy::resetEnemy(int maxH, int maxV)
{
	this->randomStart(maxH, maxV);
	// Change score here
}

std::string 		CreateBadLazer(int lazorLen, int currentH){
	std::string str= "";
	for (int i = currentH; i < lazorLen; i++){
		str.append("-");
	}
	return (str);
}

void 			immaFirinMahBadLazer(WINDOW *win, int v, int h, const char * lazor) {
		mvwprintw(win, v, h, lazor);
}

bool			withinRange(int playerH, int eneH, int maxH){
	int lazerSize = maxH / 2;
	int location = playerH + lazerSize;

	if (playerH <= lazerSize && location >= eneH)
	{
		return true;
	} else{
		return(false);
	}
}

bool 			 Enemy::shoot(WINDOW *win, int maxH ,int playerV, int playerH){
	int currentV = this->getV();
	int currentH = this->getH();
	int lazorStart;
	std::string lazer;
	int maxLazorLen = maxH / 2;

	if (currentV == playerV && (withinRange(playerH,currentH, maxH)) && (playerH <= currentH) ){
		lazorStart = currentH - maxLazorLen;
		if (lazorStart <= 0)
		{
			lazorStart = 0;
			maxLazorLen = currentH;
		}
		lazer = CreateBadLazer(maxLazorLen, playerH);
		immaFirinMahBadLazer(win, currentV, playerH, lazer.c_str());
		return (true);
	} else {
		lazorStart = currentH - maxLazorLen;
		if (lazorStart <= 0)
		{
			lazorStart = 0;
			maxLazorLen = currentH;
		}
		lazer = CreateBadLazer(maxLazorLen, 0);
		immaFirinMahBadLazer(win, currentV, lazorStart, lazer.c_str());
		return(false);
	}
}
