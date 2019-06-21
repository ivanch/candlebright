#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.hpp"

class Dressed_Zombie : public Enemy {    
    public:
        Dressed_Zombie(sf::Vector2f pos = {0,0});
        ~Dressed_Zombie();
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

        virtual short getSubType(){ return 2; }
};
