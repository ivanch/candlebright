#pragma once
#include "includes.hpp"
#include "Character.hpp"
#include "ColisionManager.hpp"
#include "Enemy.hpp"
#include "TextureManager.hpp"

class Player : public Character {
    private:
        sf::View& view;
        sf::Vector2f RespawnPos;
        sf::RectangleShape pRect;

    public:
        Player(sf::View& _view);
        ~Player();

        void setPos(sf::Vector2f newPos);
        void moveRight();
        void moveLeft();
        void jump();

        virtual sf::Vector2f getPos();
        virtual sf::FloatRect getRect();
        virtual void onUpdate();
        virtual void drawTo(sf::RenderWindow &window);
        virtual void move(sf::Vector2f vec);
        virtual void attack();
        virtual void fall();
        virtual void takeDamage(float damage);
};
