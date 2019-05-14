#include "Build.hpp"

Build::Build(sf::Vector2f size, sf::Vector2f pos, sf::Color _col){
    rect = sf::RectangleShape(size);
    rect.setFillColor(_col);
    rect.setPosition(pos);
    position = pos;
}
Build::Build(sf::Vector2f size, sf::Vector2f pos, sf::Texture* _tex){
    rect = sf::RectangleShape(size);
    rect.setTexture(_tex);
    rect.setPosition(pos);
    texture = _tex;
    position = pos;
}
Build::~Build(){}

void Build::draw(sf::RenderWindow& window){
    //rect.setTexture(texture);
    window.draw(rect);
}

sf::FloatRect Build::getRect(){
    return rect.getGlobalBounds();
}

void Build::fall(){
    //rect.move({0,0.5});
}