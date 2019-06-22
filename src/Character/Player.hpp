#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>

#include "Character.hpp"
#include "../Enemies/Enemy.hpp"

class Player : public Character {
    private:
        sf::Vector2f RespawnPos;
        std::string name;

        sf::Sprite pSprite;

        sf::Sprite wSprite; // Whip Sprite
        float whipSize;
        bool whipExpanding;

        static unsigned int score ;

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

        virtual const sf::Vector2f getPos() const;
        virtual const sf::FloatRect getRect() const;
        virtual void update();
        virtual void draw(Engine& engine);
        virtual void move(sf::Vector2f vec);
        virtual void attack();
        virtual void fall();
        virtual void takeDamage(float _damage);

        static unsigned int getScore() { return score; }
        static void setScore(unsigned int _score){ score = _score; }
};

