#pragma once
#include "includes.hpp"
#include "World.hpp"
#include "Plataform.hpp"
#include "Obstacle.hpp"
#include "TextureManager.hpp"
#include "Enemy1.hpp"

class World_1 : public World {
    private:
        vector<Entity*> entities;
    public:
        World_1();
        ~World_1();
        virtual void update();
        virtual void setAllEngine(Engine* _engine);
};