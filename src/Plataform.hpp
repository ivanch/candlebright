class Plataform{
    private:
        /* start
            x1
            y1
        */
        sf::Vector2f start;
        /* end
                    ...     x2
                    ...     y2
        */
        sf::Vector2f end;
        sf::Color color;
        sf::RectangleShape rect;
        sf::Texture texture;

    public:
        Plataform(sf::Vector2f _start, sf::Vector2f _end,
                  sf::Color _col);
        ~Plataform();

        void draw(sf::RenderWindow& window);
        sf::FloatRect getRect();
        void setTexture(string filename);
};