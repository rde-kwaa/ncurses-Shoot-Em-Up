#ifndef ENEMY_H
# define ENEMY_H
#include "../inc/Entity.hpp"
#include <iostream>

class Enemy : public Entity
{	
	private:
		int				_size;
		std::string		_type;

	public:
		Enemy(void);
		Enemy(int h, int v);
		Enemy(const Enemy &Enemy);
		~Enemy();
		Enemy &operator=(const Enemy &enemy);
		void 			randomStart(int maxH, int maxV);
		void 			resetEnemy(int maxH, int maxV);
		void			setSize(int);
		void			setType(std::string);
		int				getSize(void);
		std::string		getType(void);
};

#endif
