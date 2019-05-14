#include "Plataform.hpp"

Plataform::Plataform(sf::FloatRect shape, sf::Color _col){
    rect = sf::RectangleShape({shape.width,shape.height});
    rect.setFillColor(_col);
    rect.setPosition({shape.left,shape.top});
}
Plataform::Plataform(sf::FloatRect shape, sf::Texture* _tex){
    rect = sf::RectangleShape({shape.width,shape.height});
    rect.setTexture(_tex);
    texture = _tex;
    rect.setPosition({shape.left,shape.top});
}
Plataform::~Plataform(){}

void Plataform::draw(sf::RenderWindow& window){
    //rect.setTexture(texture);
    window.draw(rect);
}

sf::FloatRect Plataform::getRect(){
    return rect.getGlobalBounds();
}