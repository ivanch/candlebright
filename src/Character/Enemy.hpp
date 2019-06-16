#pragma once
#include "../includes.hpp"
#include "Character.hpp"

class Enemy : public Character {
    protected:
        sf::RectangleShape enemy;
        sf::Sprite eSprite;
        sf::Vector2f originalPos;
        sf::Vector2f moving;
        string name;
        float attackChance;

    public:
        virtual void attack() = 0;
};