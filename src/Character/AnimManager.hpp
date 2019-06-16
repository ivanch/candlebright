#pragma once
#include "../includes.hpp"

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
        map<string, int> modes;

        int count; // Contagem de quantas animações foram feitas

        sf::Texture* getTexture(string filename);

    public:
        AnimManager(sf::Sprite* _sprite, sf::Vector2i _size = {0,0});
        ~AnimManager();

        /*  mode = 0: vai e volta
            mode = 1: vai e volta pro começo
            mode = 2: vai e fica nos 2 ultimos, não sobrepõe   */
        void addSheet(string name, string filename, int mode = 0);
        void play(string name, bool goBack=true);
        void setScale(sf::Vector2f _scale);
        void setTime(float milliseconds){ delay = milliseconds; };
        int getStage(){ return (int)rect.left/rect.width; }
        int getCount(){ return count; }
};
