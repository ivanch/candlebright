#pragma once
#include <SFML/Graphics.hpp>

#include "../Thing.hpp"
#include "../AnimManager.hpp"
#include "../Animatable.hpp"
#include "../System/Engine.hpp"

#include "HealthBar.hpp"
#include "CharacterState.hpp"
#include "IdleState.hpp"
#include "WalkingState.hpp"
#include "JumpingState.hpp"
#include "FallingState.hpp"
#include "AttackingState.hpp"

class Character : public Animatable {
    public:
        enum Facing {
            FACING_RIGHT,
            FACING_LEFT
        };

        Character();
        virtual ~Character();
        virtual void move(sf::Vector2f _move) = 0;
        virtual void takeDamage(float _damage) = 0;
        virtual void setPos(sf::Vector2f _pos) = 0;

        /* Funções de get */
        virtual const sf::Vector2f getPos() const = 0;
        virtual const sf::Vector2f getSize() const;
        virtual const float getDamage() const;
        virtual const float getAttackSpeed() const;
        virtual sf::Clock* getAttackClock();
        virtual const float getRange() const;
        virtual const float getHealth() const;

        /*  0 = Player
            1 = Enemy */
        virtual short getType();
        /* Específico para cada "sub-classe" */
        virtual short getSubType();

        /* CharacterState com enum */
        virtual bool setState(CharacterState::State _newState);
        virtual const CharacterState::State getState();
        /* CharacterState no âmbito POO */
        virtual const CharacterState* getCharacterState();
        virtual void setCharacterState(CharacterState* _newState);

        virtual void setFacing(Facing _facing);
        virtual const short getFacing() const;

        virtual void setHealth(float _health);

        const bool isDead() const { return dead; }
        void setDead(bool _dead) { this->dead = _dead; }

    protected:
        sf::Vector2f velocity;
        float health;
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

        bool dead;
};
