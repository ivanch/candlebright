#pragma once
#include "includes.hpp"
#include "Engine.hpp"
#include "Enemy.hpp"

class Enemy_1 : public Enemy {

    public:
        Enemy_1(sf::Vector2f pos = {0,0}, string _name = "");
        ~Enemy_1();
        void setPos(sf::Vector2f newPos);
        void moveRight();
        void moveLeft();

        virtual sf::Vector2f getPos();
        virtual sf::FloatRect getRect();
        virtual void takeDamage(float damage);
        virtual void fall();
        virtual void update();
        virtual void draw();
        virtual void move(sf::Vector2f vec);
};
