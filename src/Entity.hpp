#pragma once
#include "includes.hpp"
#include "Engine.hpp"

class Entity {  
    protected:
        Engine* engine;

    public:
        virtual void update() = 0;
        virtual void draw() = 0;
        void setEngine(Engine* _engine){ engine = _engine; }
};