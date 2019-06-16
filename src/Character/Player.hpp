#pragma once
#include "../includes.hpp"
#include "Character.hpp"
#include "AnimManager.hpp"

class Player : public Character {
    private:
        sf::Vector2f RespawnPos;
        string name;

        sf::Clock spriteClock;
        sf::Sprite pSprite;
        AnimManager anim;

        sf::Keyboard::Key key_right;
        sf::Keyboard::Key key_left;
        sf::Keyboard::Key key_jump;
        sf::Keyboard::Key key_attack;

    public:
        Player(int _template=-1);
        ~Player();

        void setPos(sf::Vector2f newPos);
        void moveRight();
        void moveLeft();
        void jump();

        virtual sf::Vector2f getPos();
        virtual sf::FloatRect getRect();
        virtual void update();
        virtual void draw(Engine* engine);
        virtual void move(sf::Vector2f vec);
        virtual void attack();
        virtual void fall();
        virtual void takeDamage(Character* issuer, float damage);
        virtual void death(){}
};