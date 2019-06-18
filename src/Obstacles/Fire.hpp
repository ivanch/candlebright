#pragma once
#include "../includes.hpp"
#include "Obstacle.hpp"
#include "../Thing.hpp"
#include "../AnimManager.hpp"

class Fire : public Obstacle {
    private:
        AnimManager anim;
        sf::Clock animClock;
    
    public:
        Fire(sf::Vector2f pos, float _size);
        ~Fire();

        virtual float getDamage();
        virtual void update();
        virtual void draw(Engine* engine);
        virtual sf::Vector2f getPos();
    
};