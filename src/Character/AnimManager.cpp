#include "AnimManager.hpp"

AnimManager::AnimManager(sf::Sprite* _sprite, sf::Vector2i _size){
    sprite = _sprite;
    rect = {0,0,_size.x,_size.y};
    size = _size;
    scale = {1,1};
    goingBack = false;
    count = 0;
    locked = false;

    sprite->setOrigin({(float)size.x/2, 0.0});
}
AnimManager::~AnimManager(){
    for(auto itr = animes.begin(); itr != animes.end(); ++itr){
        delete (*itr).second;
    }
    animes.clear();
}

void AnimManager::play(string name, bool lock){
    if(name == current){
        sprite->setTextureRect(rect);
        if(modes[name] == 0){
            if(goingBack) rect.left -= rect.width;
            else rect.left += rect.width;
            if(rect.left+rect.width >= static_cast<signed>(animes[current]->getSize().x-rect.width)){
                goingBack = true;
            }else if(rect.left <= 0){
                goingBack = false;
            }
        }else if(modes[name] == 1){
            if(goingBack) rect.left -= rect.width;
            else rect.left += rect.width;
            if(rect.left+rect.width >= static_cast<signed>(animes[current]->getSize().x-rect.width)){
                rect.left = 0;
            }
        }else if(modes[name] == 2){
            if(goingBack){
                rect.left -= rect.width;
                goingBack = false;
            }else rect.left += rect.width;
            if(rect.left+rect.width >= static_cast<signed>(animes[current]->getSize().x-rect.width)){
                goingBack = true;
            }
        }else if(modes[name] == 3){
            rect.left += rect.width;
            if(rect.left >= static_cast<signed>(animes[current]->getSize().x-rect.width)){
                locked = false;
                current = "NULL";
            }
        }else if(modes[name] == 4){
            if(rect.left < static_cast<signed>(animes[current]->getSize().x-rect.width)){
                rect.left += rect.width;
            }
        }
        count++;
    }else{
        try {
            animes.at(name);
        }catch (const std::out_of_range& oor) {
            std::cerr << "Out of Range error: " << oor.what() << endl;
        }
        if(locked){
            play(current, lock);
            return;
        }
        locked = lock;
        count = 0;
        rect.left = 0;
        sprite->setTextureRect(rect);
        sprite->setTexture(*animes[name]);
        current = name;
    }
}

void AnimManager::stop(){
    current = "NULL";
    locked = false;
}

void AnimManager::setScale(sf::Vector2f _scale){
    if(scale == _scale) return;
    sprite->setOrigin({(float)size.x/2, 0.0});
    
    sprite->setScale(_scale);
    scale = _scale;
}

void AnimManager::addSheet(string name, string filename, int mode){
    if(mode < 0 || mode > 4) mode = 0;
    sf::Texture* tex = new sf::Texture;
    if(!tex->loadFromFile(filename)){
        cerr << "Não foi possível ler textura do arquivo: " << filename << endl;
    }
    animes.insert(pair<string, sf::Texture*>(name, tex));
    modes.insert(pair<string, int>(name, mode));
}