#pragma once
#include "includes.hpp"
#include "Engine.hpp"
#include "TextureManager.hpp"

class Entity {  
    protected:
        TextureManager* texManager;

    public:
        Entity() { texManager = TextureManager::getInstance(); }
        virtual void update() = 0;
        virtual void draw(Engine* engine) = 0;
};