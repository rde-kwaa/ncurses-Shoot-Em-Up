#include "../inc/Entity.hpp"
#include <iostream>

Entity::Entity(void){
		return;
	}
	Entity::Entity(int h, int v){
		this->_h = h;
		this->_v = v;
		return ;
	}
	Entity::Entity(const Entity &entity){
		*this = entity;
		return ;
	}
	Entity::~Entity(void){
		return ;
	}
	// void    Entity::updatePosition(){
	//     this->setH(this->getH() + this->getSpeed());
	//     if(this->getH() > this->getMaxH())
	//         this->setH(this->getMaxH());
	//     return ;
	// }

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
	int Entity::getSpeed(){
		return this->_speed;
	}
	std::string Entity::getCharacter(){
		return this->_character;
	}

	Entity &Entity::operator=(const Entity &entity){
		this->_character = entity._character;
		this->_h = entity._h;
		this->_v = entity._v;
		this->_speed = entity._speed;
		return (*this);
	}
