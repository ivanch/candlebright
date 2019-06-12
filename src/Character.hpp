#pragma once
#include "includes.hpp"
#include "Object.hpp"

class Character : public Object {
    public:
        virtual sf::Vector2f getPos() = 0;
        virtual void move(sf::Vector2f _move) = 0;
        virtual void takeDamage(float damage) = 0;

    protected:
        sf::Vector2f velocity;
        unsigned int health;
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
