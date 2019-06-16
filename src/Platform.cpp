#include "Platform.hpp"

Platform::Platform(sf::Vector2f size, sf::Vector2f pos, sf::Color _col):
    originalPos(pos){
    rect = sf::RectangleShape(size);
    rect.setFillColor(_col);
    rect.setPosition(pos);
    mRight = false;
    mUp = false;
    sprite = NULL;
    texture = NULL;
    moving = false;
}
Platform::Platform(sf::Vector2f size, sf::Vector2f pos, sf::Texture* _tex):
    originalPos(pos){
    cout<<_tex<<endl;
    rect = sf::RectangleShape(size);
    if(_tex!=NULL){
    rect.setTexture(_tex);}
    rect.setPosition(pos);
    sprite = NULL;
    moving = false;
    texture = _tex;
}
Platform::Platform(sf::Vector2f size, sf::Vector2f pos, sf::Sprite* _spr):
    originalPos(pos){
    sprite = _spr;
    sprite->setPosition(pos);
    sprite->setScale(size.x/_spr->getLocalBounds().width, size.y/_spr->getLocalBounds().height);
    texture = NULL;
    moving = false;
}
Platform::~Platform(){}

void Platform::draw(Engine* engine){
    if(sprite != NULL) engine->draw(*sprite);
    else engine->draw(rect);
}

void Platform::update(){
    if(moving){
        fmove();
    }
    if(texture != NULL) rect.setTexture(texture);
}

sf::FloatRect Platform::getRect(){
    if(sprite == NULL) return rect.getGlobalBounds();
    else return sprite->getGlobalBounds();
}

void Platform::setMoveSpeed(sf::Vector2f _vel){
    vel = _vel;
}

void Platform::setMove(sf::Vector2f _move){
    move = _move;
    if(_move != sf::Vector2f(0,0)) moving = true;
}

void Platform::setMoving(bool _moving){
    moving = _moving;
}

void Platform::fmove(){
    sf::Vector2f pos = rect.getPosition();
    if(mRight){
        rect.move({-vel.x,0});
        if(abs(pos.x) < abs(originalPos.x-move.x)) mRight = false;
    }else{
        rect.move({vel.x,0});
        if(abs(pos.x) > abs(originalPos.x+move.x)) mRight = true;
    }
    if(mUp){
        rect.move({0,-vel.y});
        if(abs(pos.y) < abs(move.y-originalPos.y)) mUp = false;
    }else{
        rect.move({0,vel.y});
        if(abs(pos.y) > abs(move.y+originalPos.y)) mUp = true;
    }
}
