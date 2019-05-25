#pragma once
#include "includes.hpp"

class Object{
    public:
        static vector<Object*> objects;
        Object();
        ~Object();
        virtual sf::FloatRect getRect(){ return {0,0,0,0}; }
        virtual void drawTo(sf::RenderWindow& window) = 0;


};
