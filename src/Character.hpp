#pragma once
#include "includes.hpp"
#include "Listener.hpp"
#include "Object.hpp"

class Character : private Listener, public Object{
    public:
        Character();
        ~Character();
        static vector<Character*> characters;
        
        virtual sf::FloatRect getRect() = 0;
        virtual sf::Vector2f getPos() = 0;
        virtual void move(sf::Vector2f _move) = 0;
        virtual void drawTo(sf::RenderWindow& window) = 0;
        virtual void takeDamage(float damage) = 0;

    protected:
        sf::Vector2f velocity;
        int health;
        int score;
        float moveSpeed;
        float jumpHeight;
        float finalJumpHeight;
        float maxSlideX;
        float maxSlideY;
        float damage;
        bool isJumping;

        sf::Clock attackTimer;
        float attackSpeed; // Ataques por segundo
};
