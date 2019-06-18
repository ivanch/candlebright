#include "BlackHole.hpp"

Black_Hole::Black_Hole(sf::Vector2f pos): anim(&oSprite, {35,33}){
    oSprite.setPosition(pos);
    anim.addSheet("Black_Hole", "sprites/Obstacle/new-Black-Hole.png", 1);
    position = pos;
    type = 2;
    damage = 5;
    attackRate = 1000;
}
Black_Hole::~Black_Hole(){}

void Black_Hole::update(){
    if(animClock.getElapsedTime().asMilliseconds() > 200){
        anim.play("Black_Hole");
        oSprite.setScale({3,3});
        animClock.restart();
    }
}

void Black_Hole::draw(Engine* engine){
    engine->draw(oSprite);
}

float Black_Hole::getDamage(){
    return damage;
}

sf::Vector2f Black_Hole::getPos(){
    return position;
}