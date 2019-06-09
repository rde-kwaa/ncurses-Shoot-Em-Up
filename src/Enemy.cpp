#include "../inc/Enemy.hpp"

Enemy::Enemy(void)
{
	return ;
}

void Enemy::randomStart(int maxH, int maxV) {
	this->_h = maxH - 1;
	int iRand = std::rand() % maxV;
	if (iRand == -1 || iRand == 0)
	{
		iRand -= 2;
	}
	this->_v = iRand;
}

Enemy::Enemy(int h, int v):Entity(h,v){
	// Enemy::Enemy(int h, int v){
	this->_h = h;
	this->_v = v;
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
	return (*this);
}

void			Enemy::setSize(int n) {
	this->_size = n;
}

void			Enemy::setType(std::string type) {
	this->_type = type;
}

int				Enemy::getSize(void) {
	return (this->_size);
}

std::string		Enemy::getType(void) {
	return (this->_type);
}

void 			Enemy::resetEnemy(int maxH, int maxV)
{
	this->randomStart(maxH, maxV);
	// Change score here
}
