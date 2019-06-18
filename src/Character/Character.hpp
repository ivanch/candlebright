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
#include "../Animatable.hpp"

class Character : public Thing, public Animatable {
    public:
        enum Facing {
            FACING_RIGHT,
            FACING_LEFT
        };

        Character();
        virtual ~Character();
        virtual sf::Vector2f getPos() = 0;
        virtual void move(sf::Vector2f _move) = 0;
        virtual void takeDamage(Thing* _issuer, float _damage) = 0;
        virtual void death() = 0;
        virtual sf::Vector2f getSize() { return {getRect().width, getRect().height}; }

        virtual float getDamage(){ return damage; }
        virtual float getAttackSpeed(){ return attackSpeed; }
        virtual sf::Clock* getAttackClock(){ return &attackTimer; }
        virtual float getRange(){ return range; }
        virtual float getHealth(){ return health; }

        /*  0 = Player
            1 = Enemy */
        virtual short getType() { return type; }
        virtual short getSubType(){ return 0; };

        virtual void setState(CharacterState::State _state);
        virtual CharacterState::State getState(){ return currentState->getState(); }

        virtual void setFacing(Facing _facing) { facing = _facing; }
        virtual short getFacing() { return facing; }

        virtual void setPos(sf::Vector2f _pos) = 0;
        virtual void setHealth(float _health){ health = _health; }

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

        CharacterState* currentState;
        short facing;

        sf::Clock attackTimer;
        float attackSpeed; // Intervalo entre os ataques em milissegundos

        short type;
};
