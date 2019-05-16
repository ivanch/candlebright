#pragma once
#include "includes.hpp"
#include "Object.hpp"

class Build: public Object {
    private:
        sf::RectangleShape rect;
        sf::Color color;
        sf::Texture* texture;
        sf::Vector2f position;

    public:
        static vector<Build*> builds;
        Build(sf::Vector2f size, sf::Vector2f pos, sf::Color _col);
        Build(sf::Vector2f size, sf::Vector2f pos, sf::Texture* _tex);
        ~Build();

        void drawTo(sf::RenderWindow& window);
        sf::FloatRect getRect();
        void fall();
};