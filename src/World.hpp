class World{
    private:
        vector<Plataform> plataforms;
        vector<Object*> objects;

    public:
        World();
        ~World();

        void draw(sf::RenderWindow& window);
        void addObject(Object* o);
        void gravity();
        bool isColliding(sf::FloatRect rect);
};