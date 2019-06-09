#include "../inc/Entity.hpp"
#include <iostream>

Entity::Entity(void){
		return;
	}
	Entity::Entity(int h, int v){
		this->_h = h;
		this->_v = v;
		this->_speed = 1;
		this->_hp = 1;
		this->_damageOut = 1;
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
		int entitydamage = entity.getDamageOutput();
		int thisdamage = this->getDamageOutput();
		if((entity.getH() == this->getH()) && (entity.getV() == this->getV()))
		{
			entity.takeDamage(thisdamage);
			this->takeDamage(entitydamage);
		}
		return ;
	}
	void    Entity::takeDamage(int damageOut){
		if(this->getHp() > 0)
			this->setHp(this->getHp()-damageOut);
		if(this->getHp() <= 0){
			this->die();
			//Enemy - reset position
			//Player - game over
			//Bullet - delete
		}
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
	int Entity::getDamageOutput(){
		return this->_damageOut;
	}
	int Entity::getHp(){
		return this->_hp;
	}
	void Entity::setHp(int hp){
		this->_hp = hp;
	}
	void Entity::setDamageOutput(int damageOut){
		this->_damageOut = damageOut;
	}
	std::string Entity::getCharacter(){
		return this->_character;
	}
	void Entity::die(){
		std::cout << "Entity has died - Please Overload this function\n";
		// delete this;
		return ;
	}
	Entity &Entity::operator=(const Entity &entity){
		this->_character = entity._character;
		this->_h = entity._h;
		this->_v = entity._v;
		this->_speed = entity._speed;
		this->_damageOut = entity._damageOut;
		this->_hp = entity._hp;
		return (*this);
	}
