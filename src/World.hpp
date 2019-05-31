#pragma once
#include "includes.hpp"
#include "Engine.hpp"

class World {
    protected:
        sf::Sprite* background;
        Engine* engine;
        
    public:
        void setBackground(sf::Sprite* _bg) { background = _bg; }
        sf::Sprite* getBackground() { return background; }
        //virtual void colisionManager() = 0;
        virtual void update() = 0; // Atualizar a lista de entidades dentro do mundo
        virtual void setAllEngine(Engine* _engine) = 0;
};