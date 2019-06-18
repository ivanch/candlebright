#pragma once
#include "../includes.hpp"
#include "Character.hpp"

class Player : public Character {
    private:
        sf::Vector2f RespawnPos;
        string name;

        sf::Sprite pSprite;

        sf::Sprite wSprite; // Whip Sprite
        float whipSize;
        bool whipExpanding;

        sf::Sprite healthBar;

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
        virtual void takeDamage(Thing* _issuer, float _damage);
        virtual void death(){}
};