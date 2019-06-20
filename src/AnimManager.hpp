#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class AnimManager {
    private:
        sf::Sprite* sprite;
        sf::Vector2i size;
        sf::IntRect rect;
        sf::Vector2f scale;
        bool goingBack;
        float delay;
        std::string current;
        std::map<std::string, sf::Texture*> animes; // animes["idle"] -> sf::Texture*
        std::map<std::string, int> modes;

        int count; // Contagem de quantas animações foram feitas
        bool locked;

        sf::Texture* getTexture(std::string filename);

    public:
        AnimManager(sf::Sprite* _sprite, sf::Vector2i _size = {0,0});
        ~AnimManager();

        /*  mode = 0: vai e volta
            mode = 1: vai e volta pro começo
            mode = 2: vai e fica nos 2 ultimos, não sobrepõe
            mode = 3: vai e destranca as animações              
            mode = 4: vai e fica, destranca depois de terminado     */
        void addSheet(std::string name, std::string filename, int mode = 0);

        /*  lock = true: não deixa outra animação sobrepor e 
                         impede que o personagem mude seu State */
        void play(std::string name, bool lock = false);
        void stop();
        
        void setScale(sf::Vector2f _scale);
        void defineRect();
        void setTime(float milliseconds){ delay = milliseconds; };
        int getStage(){ return (int)rect.left/rect.width; }
        int getCount(){ return count; }
        bool isLocked(){ return locked; }
};
