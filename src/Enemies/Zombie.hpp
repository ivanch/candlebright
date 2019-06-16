#pragma once
#include "../includes.hpp"
#include "Enemy.hpp"

class Zombie : public Enemy {
    private:
        sf::Clock spriteClock;
        sf::Sprite pSprite;
    
    public:
        Zombie(sf::Vector2f pos = {0,0}, string _name = "");
        ~Zombie();
        void setPos(sf::Vector2f newPos);
        void moveRight();
        void moveLeft();

        virtual sf::Vector2f getPos();
        virtual sf::FloatRect getRect();
        virtual void takeDamage(Character* issuer, float damage);
        virtual void fall();
        virtual void update();
        virtual void draw(Engine* engine);
        virtual void move(sf::Vector2f vec);
        virtual void attack();
        virtual void death(){}
};
