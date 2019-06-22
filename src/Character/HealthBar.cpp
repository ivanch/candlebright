#include "HealthBar.hpp"

HealthBar::HealthBar(sf::Vector2f pos){
    size = {50.0, 5.0};
    background.setPosition(pos);
    foreground.setPosition(pos);

    background.setFillColor(sf::Color(60, 0, 0));
    foreground.setFillColor(sf::Color(255, 0, 0));

    background.setSize(size);
    foreground.setSize(size);

    maxHealth = 100.0;
    health = 100.0;
}
HealthBar::~HealthBar(){}

void HealthBar::setHealth(float _health){
    health = _health;
    
    float rate = maxHealth/size.x;
    foreground.setSize({_health/rate,size.y});
}

void HealthBar::setMaxHealth(float _health){
    maxHealth = _health;
}

void HealthBar::setPos(sf::Vector2f _pos){
    background.setPosition(_pos);
    foreground.setPosition(_pos);
}

void HealthBar::setSize(sf::Vector2f _size){
    size = _size;

    float rate = maxHealth/size.x;
    foreground.setSize({health/rate,size.y});
    background.setSize({health/rate,size.y});
}

void HealthBar::draw(Engine& engine){
    engine.draw(background);
    engine.draw(foreground);
}