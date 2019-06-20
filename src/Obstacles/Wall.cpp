#include "Wall.hpp"

Wall::Wall(sf::Vector2f size, sf::Vector2f pos, sf::Color _col){
    rect = sf::RectangleShape(size);
    rect.setFillColor(_col);
    rect.setPosition(pos);
    position = pos;
    texture = NULL;
    type = 0;
}
Wall::Wall(sf::Vector2f size, sf::Vector2f pos, sf::Texture* _tex){
    rect = sf::RectangleShape(size);
    rect.setTexture(_tex);
    rect.setPosition(pos);
    texture = _tex;
    position = pos;
    texture = NULL;
    type = 0;
}
Wall::~Wall(){}

void Wall::update(){
    
}

void Wall::draw(Engine& engine){
    if(texture != NULL) rect.setTexture(texture);
    else engine.draw(rect);
}

const sf::FloatRect Wall::getRect() const {
    return rect.getGlobalBounds();
}

float Wall::getDamage(){
    return 0.0;
}