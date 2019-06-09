#ifndef ENTITY_HPP
# define ENTITY_HPP
# include <iostream>
class Entity{
    protected:
        int _speed;
        int _h;
        int _v;
        int _maxH;
        int _maxV;
        std::string _character;
    public:
        Entity(void);
        Entity(int x, int y,int maxx,int maxy);
        Entity(const Entity &entity);
        ~Entity(void);
        Entity &operator=(const Entity &entity);
        void updatePosition();
        void collide(Entity &entity);
        void takeDamage();

        int getH();
        int getV();
        int getMaxH();
        int getMaxV();
        int getSpeed();
        std::string getCharacter();

        void setH(int h);
        void setV(int y);
        void setMaxH(int h);
        void setMaxV(int v);
        void setSpeed(int speed);
        void setCharacter(std::string character);
};
#endif