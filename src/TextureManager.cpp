#include "TextureManager.hpp"

TextureManager* TextureManager::instance = NULL;

TextureManager::TextureManager(){
    _grass = getTexture("sprites/ground.png");
    _playerAnim = getTexture("sprites/CastlevaniaSheet.png");
}

TextureManager* TextureManager::getInstance(){
    if(instance == NULL){
        instance = new TextureManager();
    }
    return instance;
}

sf::Texture* TextureManager::getTexture(string filename){
    sf::Texture* _tex = new sf::Texture;
    if(!_tex->loadFromFile(filename)){
        cerr << "Não foi possível ler textura do arquivo: " << filename << endl;
        return NULL;
    }
    return _tex;
}
