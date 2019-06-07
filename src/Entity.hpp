#pragma once
#include "includes.hpp"
#include "Engine.hpp"
#include "TextureManager.hpp"

class Entity {  
    protected:
        Engine* engine;
        TextureManager* texManager;

    public:
        Entity() { texManager = TextureManager::getInstance(); }
        virtual void update() = 0;
        virtual void draw() = 0;
        void setEngine(Engine* _engine){ engine = _engine; }
};