#pragma once
#include "includes.hpp"

class TextureManager {
    protected:
        static TextureManager* instance;
        TextureManager();

        sf::Texture* _grass;
        sf::Texture* _playerAnim;
        sf::Texture* _ground;


    public:
        static TextureManager* getInstance();
        sf::Texture* getTexture(string filename);

        sf::Texture* grass(){ return _grass; }
        sf::Texture* ground2(){ return _ground; }
};
