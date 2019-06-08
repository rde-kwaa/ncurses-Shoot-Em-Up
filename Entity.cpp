#include "Entity.hpp"
#include <iostream>

Entity::Entity(void){
        return;
    }
    Entity::Entity(int x, int y,int maxx,int maxy){
        this->_h = x;
        this->_v = y;
        this->_maxH = maxx;
        this->_maxV = maxy;
        return ;
    }
    Entity::Entity(const Entity &entity){
        *this = entity;
        return ;
    }
    Entity::~Entity(void){
        std::cout << "Entity destroyed\n";
        return ;
    }
    void    Entity::updatePosition(){
        this->setH(this->getH() + this->getSpeed());
        if(this->getH() > this->getMaxH())
            this->setH(this->getMaxH());
        return ;
    }

    void    Entity::collide(Entity &entity){
        if((entity.getH() == this->getH()) && (entity.getV() == this->getV()))
        {
            entity.takeDamage();
            this->takeDamage();
        }
        return ;
    }
    void    Entity::takeDamage(){
        delete this;
    }



        void Entity::setH(int h){
            this->_h = h;
        }
        void Entity::setV(int y){
            this->_v = y;
        }
        void Entity::setMaxH(int h){
            this->_maxH = h;
        }
        void Entity::setMaxV(int v){
            this->_maxV = v;
        }
        void Entity::setSpeed(int speed){
            this->_speed = speed;
        }
        void Entity::setCharacter(std::string character){
            this->_character = character;
        }


    int Entity::getH(){
        return this->_h;
    }
    int Entity::getV(){
        return this->_v;
    }
    int Entity::getMaxH(){
        return this->_maxH;
    }
    int Entity::getMaxV(){
        return this->_maxV;
    }
    int Entity::getSpeed(){
        return this->_speed;
    }
    std::string Entity::getCharacter(){
        return this->_character;
    }