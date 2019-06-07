#pragma once
#include "includes.hpp"
#include "TextureManager.hpp"

/*  AnimManager
    Classe para gerenciar animações.
*/
class AnimManager {
    private:
        sf::Sprite* sprite;
        sf::Vector2i size;
        sf::IntRect rect;
        sf::Vector2f scale;
        int index;
        vector<sf::Texture*> animes;
        bool animBack;
        float delay;

    public:
        AnimManager(sf::Sprite* _sprite, sf::Vector2i _size = {0,0});
        ~AnimManager();

        void addAnim(string filename);
        void anim();
        void setSize(sf::Vector2i _size);
        void setScale(sf::Vector2f _scale);
        void setTime(float milliseconds){ delay = milliseconds; };
        sf::Texture* getTexture(string filename);
};