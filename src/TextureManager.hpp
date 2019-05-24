#pragma once
#include "includes.hpp"

class TextureManager{
    public:
        static sf::Texture* grass;
        static sf::Texture* playerStand;

        static sf::Texture* getTexture(string filename){
            sf::Texture* _tex = new sf::Texture;
            _tex->loadFromFile(filename);
            return _tex;
        }

    private:
        TextureManager(){}
        ~TextureManager(){}
};
sf::Texture* TextureManager::grass = TextureManager::getTexture("sprites/grass_side.png");
sf::Texture* TextureManager::playerStand = TextureManager::getTexture("sprites/StandSprite.png");
