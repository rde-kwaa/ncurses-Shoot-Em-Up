/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akay <akay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 01:04:00 by akay              #+#    #+#             */
/*   Updated: 2019/06/09 10:48:02 by akay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Game.hpp"

/* DEFAULT
   FUNCTIONS */
Game::Game(void)
{
    return ;
}

Game::Game(Player player)
{
    this->player = player;
}

Game::Game(Game const &obj)
{
    *this = obj;
}

Game    &Game::operator=(Game const &obj)
{
    (void)obj;
    return (*this);
}

Game::~Game()
{
    return ;
}




/* SETTER
   FUNCTIONS */
void    Game::setTermHeight(int termHeight)
{
    this->_termHeight = termHeight;
}

void    Game::setTermWidth(int termWidth)
{
    this->_termWidth = termWidth;
}

void    Game::setTermDimensions(int termHeight, int termWidth)
{
    setTermHeight(termHeight);
    setTermWidth(termWidth);
}

/* GETTER
   FUNCTIONS */
int     Game::getTermHeight()
{
    return (this->_termHeight);
}

int     Game::getTermWidth()
{
    return(this->_termWidth);
}

WINDOW  *Game::createWindow(int height, int width, int coY, int coX)
{
    WINDOW  *win = newwin(height, width, coY, coX);
    box(win, 0 , 0);
    
    return (win);
}

void    Game::displayPlayer(WINDOW *win, Player player)
{
    // int k = player.getCharacter().size() + 1;
    // char symbol[k];
    
    // player.getCharacter().copy(symbol, player.getCharacter().size() + 1);
    // symbol[player.getCharacter().size()] = '\0';

    mvwprintw(win, player.getV(), player.getH(), "0");
}

void        Game::getAction(WINDOW *win, int termHeight, int termWidth)
{
    int move = wgetch(win);
    switch(move)
    {
        case KEY_UP:
            this->player.moveUp(termHeight);
            break;
        case KEY_DOWN:
            this->player.moveDown(termHeight);
            break;
        case KEY_LEFT:
            this->player.moveLeft();
            break;
        case KEY_RIGHT:
            this->player.moveRight(termWidth);
            break;
        default:
            break;
    }
}
