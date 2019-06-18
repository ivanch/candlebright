#pragma once
#include "../includes.hpp"
#include "Obstacle.hpp"
#include "../Thing.hpp"

class Obstacle1 : public Obstacle {
    public:
        Obstacle1(sf::Vector2f size, sf::Vector2f pos, sf::Color _col);
        Obstacle1(sf::Vector2f size, sf::Vector2f pos, sf::Texture* _tex);
        ~Obstacle1();
        virtual void update();
        virtual void draw(Engine* engine);
        virtual sf::FloatRect getRect();
};