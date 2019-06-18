#pragma once
#include "../includes.hpp"
#include "../Thing.hpp"
#include "../AnimManager.hpp"
#include "CharacterState.hpp"
#include "IdleState.hpp"
#include "WalkingState.hpp"
#include "JumpingState.hpp"
#include "FallingState.hpp"
#include "AttackingState.hpp"
#include "../Engine.hpp"

class Character : public Thing {
    public:
        enum Facing {
            FACING_RIGHT,
            FACING_LEFT
        };

        Character();
        virtual ~Character();
        virtual sf::Vector2f getPos() = 0;
        virtual void move(sf::Vector2f _move) = 0;
        virtual void takeDamage(Thing* issuer, float damage) = 0;
        virtual void death() = 0;
        virtual sf::Vector2f getSize() { return {getRect().width, getRect().height}; }

        virtual float getDamage(){ return damage; }
        virtual float getAttackSpeed(){ return attackSpeed; }
        virtual sf::Clock* getAttackClock(){ return &attackTimer; }
        virtual float getRange(){ return range; }
        virtual float getHealth(){ return health; }
        virtual short getType() { return type; }
        virtual AnimManager* getAnim(){ return anim; }

        virtual void setState(CharacterState::State _state);
        virtual CharacterState::State getState(){ return currentState->getState(); }

        virtual void setFacing(Facing _facing) { facing = _facing; }
        virtual short getFacing() { return facing; }

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
        float range;

        AnimManager* anim;

        CharacterState* currentState;
        short facing;

        sf::Clock attackTimer;
        float attackSpeed; // Ataques por segundo

        /*  0 = Player
            1 = Enemy
            2 = Boss */
        short type;
};
