#pragma once
#include "includes.hpp"

class Engine;

class Entity {
    protected:
        Engine* engine;
    
    public:
        static vector<Entity*> entities;
        Entity();
        ~Entity();
        virtual void fall(){}
        virtual void draw() = 0;
        virtual void update() = 0;
        virtual sf::FloatRect getRect(){ return {0,0,0,0}; }
        void setEngine(Engine* _engine){ engine = _engine; }
};