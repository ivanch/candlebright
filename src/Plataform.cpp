#include "Plataform.hpp"

vector<Plataform*> Plataform::plataforms;

Plataform::Plataform(sf::Vector2f size, sf::Vector2f pos, sf::Color _col){
    rect = sf::RectangleShape(size);
    rect.setFillColor(_col);
    rect.setPosition(pos);
    plataforms.push_back(this);
}
Plataform::Plataform(sf::Vector2f size, sf::Vector2f pos, sf::Texture* _tex){
    rect = sf::RectangleShape(size);
    rect.setTexture(_tex);
    texture = _tex;
    rect.setPosition(pos);
    plataforms.push_back(this);
}
Plataform::~Plataform(){}

void Plataform::draw(sf::RenderWindow& window){
    //rect.setTexture(texture);
    window.draw(rect);
}

sf::FloatRect Plataform::getRect(){
    return rect.getGlobalBounds();
}