/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlowing <jlowing@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 00:50:20 by akay              #+#    #+#             */
/*   Updated: 2019/06/09 13:35:19 by jlowing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
#define GAME_HPP

#define DELAY 20000
#include <ncurses.h>
#include "../inc/Player.hpp"
#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/timeb.h>

class Game
{
    public:
        Player      player;

        Game(void);
        Game(Player player);
        Game(Game const &obj);
        ~Game();
        Game        &operator=(Game const &obj);
        
        // Game functions
        void        displayPlayer(WINDOW *win, Player player);

        // Setters
        void        setTermHeight(int termHeight);
        void        setTermWidth(int termWidth);
        void        setTermDimensions(int termHeight, int termWidth);
		void		setStartTime(int startTime);
        
        // Getters
        int         getTermHeight();
        int         getTermWidth();
		int			getStartTime();

        // Window functions
        WINDOW      *createWindow(int height, int width, int coY, int coX);
        void        getAction(WINDOW *win, int termHeight, int termWidth);
        void        windowClean(WINDOW *win);
        void        menu(WINDOW *win, int winHeight, int winWidth);
		void		makeScenery(WINDOW *win, int time);

        int         getMilliCount();
        int         getMilliSpan(int nStartTime);   

        // Storyline
        void        storylineBegin(WINDOW *win, int maxH);
        void        storylineFail(WINDOW *win, int maxH);     
    
    private:
        int         _termHeight;
        int         _termWidth;
		unsigned int startTime;
};


#endif
