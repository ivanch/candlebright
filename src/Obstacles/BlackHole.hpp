#pragma once
#include <SFML/Graphics.hpp>
#include "Obstacle.hpp"
#include "../Animatable.hpp"

class Black_Hole : public Obstacle, public Animatable {    
    public:
        Black_Hole(sf::Vector2f pos, float _size);
        ~Black_Hole();

        virtual float getDamage();
        virtual void update();
        virtual void draw(Engine& engine);
        virtual const sf::Vector2f getPos() const;
    
};