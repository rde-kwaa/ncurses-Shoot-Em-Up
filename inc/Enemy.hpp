#ifndef ENEMY_H
# define ENEMY_H
#include "../inc/Entity.hpp"
#include <iostream>

class Enemy:public Entity
{	
	private:
		void _randomStart();

	public:
		Enemy(int h, int v);
		Enemy(const Enemy &Enemy);
		~Enemy();
		Enemy &operator=(const Enemy &enemy);
};

#endif
