#include "Obstacle1.hpp"

Obstacle1::Obstacle1(sf::Vector2f size, sf::Vector2f pos, sf::Color _col){
    rect = sf::RectangleShape(size);
    rect.setFillColor(_col);
    rect.setPosition(pos);
    position = pos;
    texture = NULL;
}
Obstacle1::Obstacle1(sf::Vector2f size, sf::Vector2f pos, sf::Texture* _tex){
    rect = sf::RectangleShape(size);
    rect.setTexture(_tex);
    rect.setPosition(pos);
    texture = _tex;
    position = pos;
    texture = NULL;
}
Obstacle1::~Obstacle1(){}

void Obstacle1::update(){
    
}

void Obstacle1::draw(Engine* engine){
    if(texture != NULL) rect.setTexture(texture);
    else engine->draw(rect);
}

sf::FloatRect Obstacle1::getRect(){
    return rect.getGlobalBounds();
}