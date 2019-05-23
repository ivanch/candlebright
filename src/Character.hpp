#pragma once
#include "includes.hpp"

class Character
{
    public:
        Character();
        ~Character();
        static vector<Character*> characters;
        virtual sf::FloatRect getRect() = 0;
        virtual void move(sf::Vector2f _move) = 0;

    protected:
    int health;
    int score;
    float moveSpeed;
    bool isJumping;
    float jumpHeight;
    float finalJumpHeight;
    float maxSlideX;
    float maxSlideY;
    float damage;
    sf::Vector2f velocity;

    private:

};
