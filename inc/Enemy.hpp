#ifndef ENEMY_H
# define ENEMY_H
#include "../inc/Entity.hpp"
#include <iostream>

class Enemy : public Entity
{	
	private:
		void 			_randomStart();
		int				_size;
		std::string		_type;

	public:
		Enemy(int h, int v);
		Enemy(const Enemy &Enemy);
		~Enemy();
		Enemy &operator=(const Enemy &enemy);
		void			setSize(int);
		void			setType(std::string);
		int				getSize(void);
		std::string		getType(void);
};

#endif
