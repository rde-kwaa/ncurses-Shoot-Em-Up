#ifndef ENTITY_HPP
# define ENTITY_HPP
# include <iostream>
class Entity{
    protected:
        int _speed;
        int _h;
        int _v;
        std::string _character;

    public:
        Entity(void);
        Entity(int h, int v);
        Entity(const Entity &entity);
        ~Entity(void);
        Entity &operator=(const Entity &entity);
        // void updatePosition();
        void collide(Entity &entity);
        void takeDamage();

        int getH();
        int getV();
        int getSpeed();
        std::string getCharacter();

        void setH(int h);
        void setV(int y);
        void setSpeed(int speed);
        void setCharacter(std::string character);
};
#endif
