#pragma once
#include "../includes.hpp"
#include "Enemy.hpp"
#include "../Animatable.hpp"

class Sylathus : public Enemy {
    private:
        sf::Sprite sSprite;
        sf::Sprite bSprite; // Bafo sprite

        AnimManager breathAnim;
        sf::Clock breathClock;

    public:
        Sylathus(sf::Vector2f pos = {0,0});
        ~Sylathus();
        void setPos(sf::Vector2f newPos);
        void moveRight();
        void moveLeft();

        virtual sf::Vector2f getPos();
        virtual sf::FloatRect getRect();
        virtual void takeDamage(Thing* _issuer, float _damage);
        virtual void fall();
        virtual void update();
        virtual void draw(Engine* engine);
        virtual void move(sf::Vector2f vec);
        virtual void attack();
        virtual void death(){}
};
