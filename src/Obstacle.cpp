#include "Obstacle.hpp"

Obstacle::Obstacle(sf::Vector2f size, sf::Vector2f pos, sf::Color _col){
    rect = sf::RectangleShape(size);
    rect.setFillColor(_col);
    rect.setPosition(pos);
    position = pos;
}
Obstacle::Obstacle(sf::Vector2f size, sf::Vector2f pos, sf::Texture* _tex){
    rect = sf::RectangleShape(size);
    rect.setTexture(_tex);
    rect.setPosition(pos);
    texture = _tex;
    position = pos;
}
Obstacle::~Obstacle(){}

void Obstacle::draw(){
    //rect.setTexture(texture);
    engine->draw(rect);
}

sf::FloatRect Obstacle::getRect(){
    return rect.getGlobalBounds();
}

void Obstacle::fall(){
    //rect.move({0,0.5}); // Gravidade da construção
}

void Obstacle::update(){
    draw();
}