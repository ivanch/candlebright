#pragma once
#include "../includes.hpp"
#include "Obstacle.hpp"
#include "../Thing.hpp"
#include "../AnimManager.hpp"

class Black_Hole : public Obstacle {
    private:
        AnimManager anim;
        sf::Clock animClock;
    
    public:
        Black_Hole(sf::Vector2f pos, float _size);
        ~Black_Hole();

        virtual float getDamage();
        virtual void update();
        virtual void draw(Engine* engine);
        virtual sf::Vector2f getPos();
    
};