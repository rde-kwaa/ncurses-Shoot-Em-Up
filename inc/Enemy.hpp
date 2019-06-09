#ifndef ENEMY_H
# define ENEMY_H
#include "../inc/Entity.hpp"
#include <iostream>
#include <ncurses.h>

class Enemy : public Entity
{	
	private:
		int				_size;
		std::string		_type;
		int				_phase;

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
		void			setPhase(int);
		int				getSize(void);
		std::string		getType(void);
		int				getPhase(void);
		bool 			shoot(WINDOW *win, int maxH, int playerV, int playerH);
};

#endif
