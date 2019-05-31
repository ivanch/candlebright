#pragma once
#include "includes.hpp"
#include "Character.hpp"

class Enemy : public Character {
    protected:
        sf::RectangleShape enemy;
        sf::Vector2f RespawnPos;
        string name;
        bool mLeft;
        sf::Vector2f originalPos;
        sf::Vector2f moving;
};