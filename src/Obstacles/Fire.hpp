#pragma once
#include <SFML/Graphics.hpp>
#include "Obstacle.hpp"
#include "../Animatable.hpp"

class Fire : public Obstacle, public Animatable {    
    public:
        Fire(sf::Vector2f pos, float _size);
        ~Fire();

        virtual float getDamage();
        virtual void update();
        virtual void draw(Engine& engine);
        virtual const sf::Vector2f getPos() const;
    
};