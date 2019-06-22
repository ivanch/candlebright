#pragma once

#include <SFML/Graphics.hpp>
#include "../Thing.hpp"

namespace Obstacles {

    class Obstacle : public Thing {
        protected:
            short type;
            float damage;
            float attackRate; // Milisegundo por ataque
            float size;
            float range;
            sf::Clock attackClock;
            sf::Sprite oSprite;
            sf::Texture* texture;
            sf::Vector2f position;

        public:
            Obstacle(){ damage = 0.0f; }
            virtual ~Obstacle(){}

            virtual const float getRange() const { return range; };
            virtual const float getDamage() const  { return damage; };
            virtual const float getAttackRate() const { return attackRate; }
            virtual sf::Clock* getAttackClock() { return &attackClock; }
            
            /*  0 = Platform
                1 = Wall
                2 = Fire
                3 = Black Hole
            */
            const short getType() const { return type; }

    };

}