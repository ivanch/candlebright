#include "AnimManager.hpp"

AnimManager::AnimManager(sf::Sprite* _sprite, sf::Vector2i _size){
    sprite = _sprite;
    rect = {0,0,_size.x,_size.y};
    size = _size;
    scale = {1,1};
    goingBack = false;

    sprite->setOrigin({(float)size.x/2, 0.0});
}
AnimManager::~AnimManager(){
    for(auto itr = animes.begin(); itr != animes.end(); ++itr){
        delete (*itr).second;
    }
    animes.clear();
}

void AnimManager::play(string name, bool goBack){
    if(name == current){
        sprite->setTextureRect(rect);
        if(goingBack) rect.left -= rect.width;
        else rect.left += rect.width;
        if(goBack && rect.left+rect.width >= animes[current]->getSize().x-rect.width){
            goingBack = true;
        }else if(rect.left <= 0){
            goingBack = false;
        }
    }else{
        try {
            animes.at(name);
        }catch (const std::out_of_range& oor) {
            std::cerr << "Out of Range error: " << oor.what() << endl;
        }
        sprite->setTexture(*animes[name]);
        current = name;
    }
}

void AnimManager::setScale(sf::Vector2f _scale){
    if(scale == _scale) return;
    sprite->setOrigin({(float)size.x/2, 0.0});
    
    sprite->setScale(_scale);
    scale = _scale;
}

void AnimManager::addSheet(string name, string filename){
    sf::Texture* tex = new sf::Texture;
    if(!tex->loadFromFile(filename)){
        cerr << "Não foi possível ler textura do arquivo: " << filename << endl;
    }
    animes.insert(pair<string, sf::Texture*>(name, tex));
}