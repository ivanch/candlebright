#include "AnimManager.hpp"

AnimManager::AnimManager(sf::Sprite* _sprite, sf::Vector2i _size){
    sprite = _sprite;
    size = _size;
    animBack = false;
    rect = {0,0,_size.x,_size.y};
    sprite->setOrigin({(float)_size.x/2,0.0});
    scale = {1,1};
    index = 0;
}
AnimManager::~AnimManager(){
    for(auto itr = animes.begin(); itr != animes.end(); ++itr){
        delete *itr;
    }
    animes.clear();
}

void AnimManager::addAnim(string filename){
    animes.push_back(getTexture(filename));
}

void AnimManager::setSize(sf::Vector2i _size){
    size = _size;
    rect = {0,0,_size.x,_size.y};
    sprite->setOrigin({(float)_size.x/2,0.0});
}

void AnimManager::anim(){
    sprite->setTexture(*animes[index]);
    sprite->setScale(scale);
    if(animBack){
        index--;
    }else{
        index++;
    }
    if(index >= animes.size()-1) animBack = true;
    else if(index == 0) animBack = false;
}

void AnimManager::setScale(sf::Vector2f _scale){
    if(scale == _scale) return;
    sprite->setScale(_scale);
    scale = _scale;
}

sf::Texture* AnimManager::getTexture(string filename){
    sf::Texture* _tex = new sf::Texture;
    if(!_tex->loadFromFile(filename)){
        cerr << "Não foi possível ler textura do arquivo: " << filename << endl;
        return NULL;
    }
    return _tex;
}
