#pragma once

#include <SFML/Graphics.hpp>
#include "AnimManager.hpp"

class Animatable {
    protected:
        AnimManager* anim;
        sf::Clock animClock;

    public:
        virtual AnimManager* getAnim(){ return anim; }
};