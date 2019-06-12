#pragma once
#include "includes.hpp"
#include "Engine.hpp"
#include "Entity.hpp"
#include "Object.hpp"
#include "LinkedList.hpp"
#include "EntityList.hpp"
#include "Music.hpp"

class World : public Entity {
    protected:
        sf::Sprite* background;
        EntityList entities;
        LinkedList<Object> objects;

    public:
        void setBackground(sf::Sprite* _bg) { background = _bg; }
        sf::Sprite* getBackground() { return background; }
        void addObject(Object* _e) { entities.entity_list.insertBack(static_cast<Entity*>(_e)); objects.insertBack(static_cast<Object*>(_e)); }
        void update(); // Atualizar a lista de entidades dentro do mundo
        void draw(Engine* engine);
        void drawAll(Engine* engine);
        void gravity();
        void collisionManager();
};
