#pragma once
#include "../includes.hpp"
#include "../Thing.hpp"

class Obstacle : public Thing {
    protected:
        short type;
        float damage;
        float attackRate; // Milisegundo por ataque
        float size;
        sf::Clock attackClock;
        sf::Sprite oSprite;
        sf::Texture* texture;
        sf::Vector2f position;

    public:
        Obstacle(){ damage = 0.0; }
        virtual ~Obstacle(){}

        virtual float getDamage() = 0;
        virtual float getAttackRate(){ return attackRate; }
        
        /*  0 = Platform
            1 = Wall
            2 = Fire
            3 = Black Hole
        */
        short getType(){ return type; }
        virtual sf::Clock* getAttackClock(){ return &attackClock; }

};