#pragma once
#include "../includes.hpp"
#include "Obstacle.hpp"
#include "../Thing.hpp"

class Wall : public Obstacle {
    private:
        sf::RectangleShape rect;
        sf::Color color;

    public:
        Wall(sf::Vector2f size, sf::Vector2f pos, sf::Color _col);
        Wall(sf::Vector2f size, sf::Vector2f pos, sf::Texture* _tex);
        ~Wall();
        virtual void update();
        virtual void draw(Engine* engine);
        virtual sf::FloatRect getRect();

        virtual float getDamage();
};