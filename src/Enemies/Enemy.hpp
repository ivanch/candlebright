#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "../Character/Character.hpp"

class Enemy : public Character {
    protected:
        sf::Sprite eSprite;
        sf::Vector2f originalPos;
        sf::Vector2f moving;
        std::string name;
        float attackChance; // Chance de ataque a cada 1/60 segundos

    public:
        Enemy();
        virtual ~Enemy();
        virtual void attack() = 0;
        virtual void setPos(sf::Vector2f _pos);
        virtual const sf::Vector2f getPos();
        
        static unsigned int enemyCount;
};