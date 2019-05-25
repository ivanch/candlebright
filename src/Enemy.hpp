#pragma once
#include "includes.hpp"
#include "ColisionManager.hpp"
#include "Engine.hpp"
#include "Character.hpp"

class Enemy : public Character {

    public:
        Enemy(sf::Vector2f pos = {0,0}, string _name = "");
        ~Enemy();
        void setPos(sf::Vector2f newPos);
        void moveRight();
        void moveLeft();

        virtual sf::Vector2f getPos();
        virtual sf::FloatRect getRect();
        virtual void takeDamage(float damage);
        virtual void fall();
        virtual void onUpdate();
        virtual void drawTo(sf::RenderWindow &window);
        virtual void move(sf::Vector2f vec);

    protected:
        sf::RectangleShape enemy;
        sf::Vector2f RespawnPos;
        string name;
        bool mRight;
        bool mLeft;
        sf::Vector2f originalPos;
        sf::Vector2f moving;


};
