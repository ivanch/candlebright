#pragma once

#include <SFML/Graphics.hpp>
#include "../System/Engine.hpp"

class HealthBar {
    private:
        sf::RectangleShape background;
        sf::RectangleShape foreground;
        sf::Vector2f size;

    public:
        HealthBar(sf::Vector2f pos = {0,0});
        ~HealthBar();

        void setPos(sf::Vector2f _pos);
        void setSize(sf::Vector2f _size);
        void setHealth(float health);

        void draw(Engine& engine);
};