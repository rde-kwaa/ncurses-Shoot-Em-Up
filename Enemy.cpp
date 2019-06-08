#include "Enemy.hpp"
#include "Enemy.hpp"

void Enemy::_randomStart() {
	srand(time(NULL));
	this->_h = this->_maxH;
	this->_v = std::rand() % this->_maxV;
}

Enemy::Enemy(int x, int y,int maxx,int maxy){
	this->_h = x;
	this->_v = y;
	this->_maxH = maxx;
	this->_maxV = maxy;
	_randomStart();
	return ;
}
Enemy::Enemy(const Enemy &Enemy){
	*this = Enemy;
	return ;
}
Enemy::~Enemy(void){
	std::cout << "Enemy destroyed\n";
	return ;
}

Entity &Entity::operator=(const Entity &entity){
	this->_character = entity._character;
	this->_h = entity._h;
	this->_v = entity._v;
	this->_maxV = entity._maxV;
	this->_maxH = entity._maxH;
	this->_speed = entity._speed;
	return (*this);
}