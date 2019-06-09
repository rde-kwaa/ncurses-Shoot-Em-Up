/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlowing <jlowing@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 00:50:20 by akay              #+#    #+#             */
/*   Updated: 2019/06/09 13:54:11 by rde-kwaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
#define GAME_HPP

#define DELAY 20000
#include <ncurses.h>
#include <sys/timeb.h>
#include <unistd.h>
#include <cstdlib>
#include <iostream>
#include "../inc/Player.hpp"

class Game {
   public:
    Player player;

    Game(void);
    Game(Player player);
    Game(Game const &obj);
    ~Game();
    Game &operator=(Game const &obj);

    // Game functions
    void displayPlayer(WINDOW *win, Player player);

    // Setters
    void setTermHeight(int termHeight);
    void setTermWidth(int termWidth);
    void setTermDimensions(int termHeight, int termWidth);

        int         getMilliCount();
        int         getMilliSpan(int nStartTime);   

        // Storyline
        void        storylineBegin(WINDOW *win, int maxH);
        void        storylineFail(WINDOW *win, int maxH);     
    
    private:
        int         _termHeight;
        int         _termWidth;
};
    // Getters
    int getTermHeight();
    int getTermWidth();

    // Window functions
    WINDOW *createWindow(int height, int width, int coY, int coX);
    void getAction(WINDOW *win, int termHeight, int termWidth);
    void windowClean(WINDOW *win);
    int menu(WINDOW *win, int winHeight, int winWidth);
    int help(WINDOW *win, int winHeight);

    int getMilliCount();
    int getMilliSpan(int nStartTime);

   private:
    int _termHeight;
    int _termWidth;
};

#endif
