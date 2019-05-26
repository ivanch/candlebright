#pragma once
#include "includes.hpp"
#include "Plataform.hpp"
#include "Build.hpp"
#include "Object.hpp"
#include "TextureManager.hpp"

class World{
    private:
        sf::Sprite* background;

    public:
        World();
        ~World();
        void setBackground(sf::Sprite* _bg){ background = _bg; }
        const sf::Sprite* getBackground(){ return background; }
};