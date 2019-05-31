#include "Plataform.hpp"

Plataform::Plataform(sf::Vector2f size, sf::Vector2f pos, sf::Color _col):
    originalPos(pos){
    rect = sf::RectangleShape(size);
    rect.setFillColor(_col);
    rect.setPosition(pos);
    mRight = false;
    mUp = false;
    texture = NULL;
}
Plataform::Plataform(sf::Vector2f size, sf::Vector2f pos, sf::Texture* _tex):
    originalPos(pos){
    rect = sf::RectangleShape(size);
    rect.setTexture(_tex);
    texture = _tex;
    rect.setPosition(pos);
}
Plataform::~Plataform(){}

void Plataform::draw(){
    engine->draw(rect);
}

void Plataform::update(){
    if(moving){
        fmove();
    }
    if(texture != NULL) rect.setTexture(texture);
    draw();
}

sf::FloatRect Plataform::getRect(){
    return rect.getGlobalBounds();
}

void Plataform::setMoveSpeed(sf::Vector2f _vel){
    vel = _vel;
}

void Plataform::setMove(sf::Vector2f _move){
    move = _move;
}

void Plataform::setMoving(bool _moving){
    moving = _moving;
}

void Plataform::fmove(){
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
