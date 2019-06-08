#ifndef ENEMY_H
# define ENEMY_H
#include "Entity.hpp"
#include <iostream>

class Enemy:public Entity
{
	public:
		void randomStart();
		Enemy(/* args */);
		~Enemy();
};

#endif // !ENEMY_H