#include "Plataform.hpp"

Plataform::Plataform(sf::Vector2f _start, sf::Vector2f _end, sf::Color _col):
        rect({_end.x - _start.x, _end.y - _start.y}){
    rect.setPosition({_start.x,_start.y});
    rect.setFillColor(_col);
    start = _start;
    end = _end;
}
Plataform::~Plataform(){}

void Plataform::draw(sf::RenderWindow& window){
    window.draw(rect);
}

sf::FloatRect Plataform::getRect(){
    return rect.getGlobalBounds();
}