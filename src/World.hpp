#pragma once
#include "includes.hpp"
#include "Engine.hpp"
#include "Entity.hpp"
#include "Object.hpp"
#include "utils.hpp"

class World : public Entity {
    protected:
        sf::Sprite* background;
        vector<Entity*> entities;
        vector<Object*> objects;
        
    public:
        void setBackground(sf::Sprite* _bg) { background = _bg; }
        sf::Sprite* getBackground() { return background; }
        //virtual void colisionManager() = 0;
        void addEntity(Entity* _e) { entities.push_back(static_cast<Entity*>(_e)); objects.push_back(static_cast<Object*>(_e)); }
        void update(); // Atualizar a lista de entidades dentro do mundo
        void draw();
        void setAllEngine(Engine* _engine);
        void gravity();
        void collisionManager();
};