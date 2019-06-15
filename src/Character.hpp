#pragma once
#include "includes.hpp"
#include "Thing.hpp"

class Character : public Thing {
    public:
        Character(){ attacking = false; }
        virtual ~Character(){}
        virtual sf::Vector2f getPos() = 0;
        virtual void move(sf::Vector2f _move) = 0;
        virtual void takeDamage(Character* issuer, float damage) = 0;
        virtual void death() = 0;
        virtual int getType() { return type; }

        virtual bool isAttacking(){ return attacking; }
        virtual void setAttacking(bool _att){ attacking = _att; }
        virtual float getDamage(){ return damage; }
        virtual float getHealth(){ return health; }

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
        bool attacking;

        /*  0 = Player
            1 = Enemy
            2 = Boss */
        int type;
};
