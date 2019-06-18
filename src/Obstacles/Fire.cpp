#include "Fire.hpp"

Fire::Fire(sf::Vector2f pos): anim(&oSprite, {20,60}){
    oSprite.setPosition(pos);
    anim.addSheet("fire", "sprites/Obstacle/new-Fire.png");
    position = pos;
    type = 1;
    damage = 0.1;
    attackRate = 250;
}
Fire::~Fire(){}

void Fire::update(){
    if(animClock.getElapsedTime().asMilliseconds() > 200){
        anim.play("fire");
        animClock.restart();
    }
}

void Fire::draw(Engine* engine){
    engine->draw(oSprite);
}

float Fire::getDamage(){
    return damage;
}

sf::Vector2f Fire::getPos(){
    return position;
}