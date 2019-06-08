#include "Enemy.hpp"
#include "Entity.hpp"

void Enemy::randomStart() {
	this->h = this->hMax;
	this->v = std::rand() % this->vMax-1;
}
Enemy::Enemy()
{
	randomStart();
}

Enemy::~Enemy()
{
}