#pragma once
#include "includes.hpp"
#include "Character.hpp"
#include "ColisionManager.hpp"
#include "Enemy1.hpp"
#include "TextureManager.hpp"
#include "AnimManager.hpp"

class Player : public Character {
    private:
        sf::View* view;
        sf::Vector2f RespawnPos;
        string name;

        sf::Clock spriteClock;
        AnimManager stand;
        AnimManager run;
        bool isMoving;
        bool isMovingRight;
        sf::Sprite pSprite;

    public:
        Player(sf::View* _view);
        ~Player();

        void setPos(sf::Vector2f newPos);
        void moveRight();
        void moveLeft();
        void jump();

        virtual sf::Vector2f getPos();
        virtual sf::FloatRect getRect();
        virtual void update();
        virtual void draw();
        virtual void move(sf::Vector2f vec);
        virtual void attack();
        virtual void fall();
        virtual void takeDamage(float damage);
};
