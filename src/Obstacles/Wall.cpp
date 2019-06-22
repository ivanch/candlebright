#include "Wall.hpp"

Obstacles::Wall::Wall(sf::Vector2f size, sf::Vector2f pos, sf::Color _col){
    rect = sf::RectangleShape(size);
    rect.setFillColor(_col);
    rect.setPosition(pos);
    position = pos;
    texture = NULL;
    type = 0;
}
Obstacles::Wall::Wall(sf::Vector2f size, sf::Vector2f pos, sf::Texture* _tex){
    rect = sf::RectangleShape(size);
    rect.setTexture(_tex);
    rect.setPosition(pos);
    texture = _tex;
    position = pos;
    texture = NULL;
    type = 0;
}
Obstacles::Wall::~Wall(){}

void Obstacles::Wall::update(){
    
}

void Obstacles::Wall::draw(Engine& engine){
    if(texture != NULL) rect.setTexture(texture);
    else engine.draw(rect);
}

const sf::FloatRect Obstacles::Wall::getRect() const {
    return rect.getGlobalBounds();
}