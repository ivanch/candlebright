#include "Platform.hpp"

Obstacles::Platform::Platform(sf::Vector2f size, sf::Vector2f pos, sf::Color _col):
    originalPos(pos){
    rect = sf::RectangleShape(size);
    rect.setFillColor(_col);
    rect.setPosition(pos);
    mRight = false;
    mUp = false;
    sprite = NULL;
    texture = NULL;
    moving = false;
    type = 0;
}
Obstacles::Platform::Platform(sf::Vector2f size, sf::Vector2f pos, sf::Texture* _tex):
    originalPos(pos){
    rect = sf::RectangleShape(size);
    if(_tex!=NULL){
    rect.setTexture(_tex);}
    rect.setPosition(pos);
    sprite = NULL;
    moving = false;
    texture = _tex;
    type = 0;
}
Obstacles::Platform::Platform(sf::Vector2f size, sf::Vector2f pos, sf::Sprite* _spr):
    originalPos(pos){
    sprite = _spr;
    sprite->setPosition(pos);
    sprite->setScale(size.x/_spr->getLocalBounds().width, size.y/_spr->getLocalBounds().height);
    texture = NULL;
    moving = false;
    type = 0;
}
Obstacles::Platform::~Platform(){}

void Obstacles::Platform::draw(Engine& engine){
    if(sprite != NULL) engine.draw(*sprite);
    else engine.draw(rect);
}

void Obstacles::Platform::update(){
    if(moving){
        fmove();
    }
    if(texture != NULL) rect.setTexture(texture);
}

const sf::FloatRect Obstacles::Platform::getRect() const {
    if(sprite == NULL) return rect.getGlobalBounds();
    else return sprite->getGlobalBounds();
}

void Obstacles::Platform::setMoveSpeed(sf::Vector2f _vel){
    vel = _vel;
}

void Obstacles::Platform::setMove(sf::Vector2f _move){
    move = _move;
    if(_move != sf::Vector2f(0,0)) moving = true;
}

void Obstacles::Platform::setMoving(bool _moving){
    moving = _moving;
}

const sf::Vector2f Obstacles::Platform::getPos() const {
    return rect.getPosition();
}

void Obstacles::Platform::fmove(){
    sf::Vector2f pos = rect.getPosition();
    if(mRight){
        rect.move(sf::Vector2f(-vel.x, 0));
        if(abs(pos.x) < abs(originalPos.x-move.x)) mRight = false;
    }else{
        rect.move(sf::Vector2f(vel.x, 0));
        if(abs(pos.x) > abs(originalPos.x+move.x)) mRight = true;
    }
    if(mUp){
        rect.move(sf::Vector2f(0, -vel.y));
        if(abs(pos.y) < abs(move.y-originalPos.y)) mUp = false;
    }else{
        rect.move(sf::Vector2f(0, vel.y));
        if(abs(pos.y) > abs(move.y+originalPos.y)) mUp = true;
    }
}
