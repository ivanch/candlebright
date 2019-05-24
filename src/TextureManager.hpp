#pragma once
#include "includes.hpp"
namespace {
    class TextureManager{
        public:
            static sf::Texture* grass;
            static sf::Texture* playerStand;
            static sf::Texture* playerRun;

            static sf::Texture* getTexture(string filename){
                sf::Texture* _tex = new sf::Texture;
                if(!_tex->loadFromFile(filename)){
                    cerr << "Não foi possível ler textura do arquivo: " << filename << endl;
                    return NULL;
                }
                return _tex;
            }

        private:
            TextureManager(){}
            ~TextureManager(){}
    };
    sf::Texture* TextureManager::grass = TextureManager::getTexture("sprites/grass_side.png");
    sf::Texture* TextureManager::playerStand = TextureManager::getTexture("sprites/StandSprite.png");
    sf::Texture* TextureManager::playerRun = TextureManager::getTexture("sprites/RunSheet.png");
}