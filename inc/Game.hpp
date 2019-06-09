

#include "../inc/Player.hpp"
#include "../inc/Enemy.hpp"
#include <iostream>
#include <ncurses.h>
class Game
{
    public:
        Player      player;
        Enemy       enemies[ENEMIES];
        Game(void);
        Game(Player player);
        Game(Game const &obj);
        ~Game();
        Game        &operator=(Game const &obj);
        
        // Game functions
        void        displayPlayer(WINDOW *win, Player player);
        void        displayEnemy(WINDOW *win, Enemy &enemy, int secondsElapsed);
        void        generateEnemy(int h, int v, int id);
	void        boom(void);
	void        game_Over(void);

	private:
		int         _termHeight;
		int         _termWidth;
};

#endif
