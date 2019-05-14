#pragma once
#include "includes.hpp"

class Plataform{
    private:
        sf::RectangleShape rect;
        sf::Color color;
        sf::Texture* texture;

    public:
        static vector<Plataform*> plataforms;
        Plataform(sf::Vector2f size, sf::Vector2f pos, sf::Color _col = sf::Color::White);
        Plataform(sf::Vector2f size, sf::Vector2f pos, sf::Texture* _tex);
        ~Plataform();

        void draw(sf::RenderWindow& window);
        sf::FloatRect getRect();

};
