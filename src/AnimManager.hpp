#pragma once
#include "includes.hpp"

class AnimManager {
    private:
        sf::Sprite* sprite;
        sf::Vector2i size;
        sf::IntRect rect;
        sf::Vector2f scale;
        bool goingBack;
        float delay;
        string current;
        map<string, sf::Texture*> animes; // animes["idle"] -> sf::Texture*

        sf::Texture* getTexture(string filename);

    public:
        AnimManager(sf::Sprite* _sprite, sf::Vector2i _size = {0,0});
        ~AnimManager();

        void addSheet(string name, string filename);
        void play(string name, bool goBack=true);
        void setScale(sf::Vector2f _scale);
        void setTime(float milliseconds){ delay = milliseconds; };
};
