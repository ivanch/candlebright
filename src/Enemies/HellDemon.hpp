#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.hpp"

class Hell_Demon : public Enemy {
    public:
        Hell_Demon(sf::Vector2f pos = sf::Vector2f(0.f, 0.f));
        ~Hell_Demon();
        void setPos(sf::Vector2f newPos);
        void moveRight();
        void moveLeft();

        virtual const sf::Vector2f getPos() const;
        virtual const sf::FloatRect getRect() const;
        virtual void takeDamage(float _damage);
        virtual void fall();
        virtual void update();
        virtual void draw(Engine& engine);
        virtual void move(sf::Vector2f vec);
        virtual void attack();

        virtual short getSubType(){ return 4; }
};
