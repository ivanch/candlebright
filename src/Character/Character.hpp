#pragma once
#include <SFML/Graphics.hpp>

#include "../Thing.hpp"
#include "../AnimManager.hpp"
#include "CharacterState.hpp"
#include "IdleState.hpp"
#include "WalkingState.hpp"
#include "JumpingState.hpp"
#include "FallingState.hpp"
#include "AttackingState.hpp"
#include "../System/Engine.hpp"
#include "../Animatable.hpp"
#include "HealthBar.hpp"

class Character : public Thing, public Animatable {
    public:
        enum Facing {
            FACING_RIGHT,
            FACING_LEFT
        };

        Character();
        virtual ~Character();
        virtual void move(sf::Vector2f _move) = 0;
        virtual void takeDamage(float _damage) = 0;
        virtual void death() = 0;
        virtual void setPos(sf::Vector2f _pos) = 0;

        /* Funções de get */
        virtual const sf::Vector2f getPos() const = 0;
        virtual const sf::Vector2f getSize() const { return {getRect().width, getRect().height}; }
        virtual const float getDamage() const { return damage; }
        virtual const float getAttackSpeed() const { return attackSpeed; }
        virtual sf::Clock* getAttackClock() { return &attackTimer; }
        virtual const float getRange() const { return range; }
        virtual const float getHealth() const { return health; }

        /*  0 = Player
            1 = Enemy */
        virtual short getType() { return type; }
        /* Específico para cada "sub-classe" */
        virtual short getSubType(){ return 0; };

        /* CharacterState com enum */
        virtual bool setState(CharacterState::State _newState);
        virtual const CharacterState::State getState(){ return currentState->getState(); }
        /* CharacterState no âmbito POO */
        virtual const CharacterState* getCharacterState(){ return currentState; }
        virtual void setCharacterState(CharacterState* _newState){ currentState = _newState; }

        virtual void setFacing(Facing _facing) { facing = _facing; }
        virtual const short getFacing() { return facing; }

        virtual void setHealth(float _health){ health = _health; }

    protected:
        sf::Vector2f velocity;
        unsigned int health;
        unsigned int score;
        float moveSpeed;
        float jumpHeight;
        float finalJumpHeight;
        float maxSlideX;
        float maxSlideY;
        float damage;
        float range;

        HealthBar healthBar;

        CharacterState* currentState;
        short facing;

        sf::Clock attackTimer;
        float attackSpeed; // Intervalo entre os ataques em milissegundos

        short type;
};
