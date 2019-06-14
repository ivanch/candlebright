#pragma once
#include "includes.hpp"
#include "Engine.hpp"

class Entity {

    public:
        virtual void update() = 0;
        virtual void draw(Engine* engine) = 0;
        inline sf::Texture* getTexture(string filename){
            sf::Texture* _tex = new sf::Texture;
            if(!_tex->loadFromFile(filename)){
                cerr << "Não foi possível ler textura do arquivo: " << filename << endl;
                return NULL;
            }
            return _tex;
        }
};