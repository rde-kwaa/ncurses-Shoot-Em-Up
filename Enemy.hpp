#ifndef ENEMY_H
# define ENEMY_H
#include "Entity.hpp"
#include <iostream>

class Enemy:public Entity
{	
	private:
		void _randomStart();

	public:
		Enemy(int x, int y,int maxx,int maxy);
		Enemy(const Enemy &Enemy);
		~Enemy();
		Enemy &operator=(const Enemy &enemy);
};

#endif // !ENEMY_H