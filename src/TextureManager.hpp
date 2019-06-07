#pragma once
#include "includes.hpp"

class TextureManager {
    protected:
        static TextureManager* instance;
        TextureManager();

        sf::Texture* _grass;
        sf::Texture* _playerAnim;

    public:
        static TextureManager* getInstance();
        sf::Texture* getTexture(string filename);

        sf::Texture* grass(){ return _grass; }
};