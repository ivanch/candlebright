#pragma once

#include "AnimManager.hpp"
#include "includes.hpp"

class Animatable {
    protected:
        AnimManager* anim;
        sf::Clock animClock;

    public:
        virtual AnimManager* getAnim(){ return anim; }
};