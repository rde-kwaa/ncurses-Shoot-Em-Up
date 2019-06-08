class Bullet
{
    public:
        Bullet(int h, int v, std::string c);
        ~Bullet();

        void display();
        
        bool player;
}
