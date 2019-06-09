#ifndef ENTITY_HPP
# define ENTITY_HPP
# include <iostream>
class Entity{
    protected:
        int _speed;
        int _h;
        int _v;
        int _hp;
        int _damageOut;
        std::string _character;

    public:
        Entity(void);
        Entity(int h, int v);
        Entity(const Entity &entity);
        ~Entity(void);
        Entity &operator=(const Entity &entity);
        // void updatePosition();
        void collide(Entity &entity);
        void takeDamage(int damageOut);

        int getH();
        int getV();
        int getSpeed();
        int getHp();
        int getDamageOutput();
        std::string getCharacter();
        void die();

        void setH(int h);
        void setV(int y);
        void setSpeed(int speed);
        void setHp(int hp);
        void setDamageOutput(int damageOut);
        void setCharacter(std::string character);
};
#endif
