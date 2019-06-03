#pragma once
#include "includes.hpp"
#include "Object.hpp"

class Obstacle : public Object {
    protected:
        sf::RectangleShape rect;
        sf::Color color;
        sf::Texture* texture;
        sf::Vector2f position;
};