#include "HealthBar.hpp"

HealthBar::HealthBar(sf::Vector2f pos){
    size = {50.0, 5.0};
    background.setPosition(pos);
    foreground.setPosition(pos);

    background.setFillColor(sf::Color(60, 0, 0));
    foreground.setFillColor(sf::Color(255, 0, 0));

    background.setSize(size);
    foreground.setSize(size);
}
HealthBar::~HealthBar(){}

void HealthBar::setHealth(float health){
    foreground.setSize({health/(100.0/size.x),5});
}

void HealthBar::setPos(sf::Vector2f _pos){
    background.setPosition(_pos);
    foreground.setPosition(_pos);
}

void HealthBar::setSize(sf::Vector2f _size){
    size = _size;

    background.setSize(size);
    foreground.setSize(size);
}

void HealthBar::draw(Engine* engine){
    engine->draw(background);
    engine->draw(foreground);
}