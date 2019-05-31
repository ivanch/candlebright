#pragma once
#include "includes.hpp"
#include "Entity.hpp"
#include "Engine.hpp"

class Obstacle : public Entity {
    private:
        sf::RectangleShape rect;
        sf::Color color;
        sf::Texture* texture;
        sf::Vector2f position;

    public:
        Obstacle(sf::Vector2f size, sf::Vector2f pos, sf::Color _col);
        Obstacle(sf::Vector2f size, sf::Vector2f pos, sf::Texture* _tex);
        ~Obstacle();

        virtual void draw();
        virtual sf::FloatRect getRect();
        virtual void fall();
        virtual void update();
};