#pragma once
#include "includes.hpp"
#include "Thing.hpp"

class Obstacle : public Thing {
    protected:
        sf::RectangleShape rect;
        sf::Color color;
        sf::Texture* texture;
        sf::Vector2f position;
};