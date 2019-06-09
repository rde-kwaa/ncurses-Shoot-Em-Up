#include "../inc/Enemy.hpp"

void Enemy::_randomStart() {
	srand(time(NULL));
	// this->_h = this->_maxH;
	// this->_v = std::rand() % this->_maxV;
}

Enemy::Enemy(int h, int v):Entity(h,v){
	_randomStart();
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
