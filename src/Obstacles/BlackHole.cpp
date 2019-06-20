#include "BlackHole.hpp"

Black_Hole::Black_Hole(sf::Vector2f pos, float _size){
    oSprite.setPosition(pos);
    position = pos;
    type = 3;

    anim = new AnimManager(&oSprite, {35,33});
    anim->addSheet("hole", "sprites/Obstacle/new-Black-Hole.png", 1);
    anim->defineRect();

    // Computa o ataque, taxa de ataque, dano e tamanho
    anim->setScale({_size/35,_size/33}); // Tamanho
    damage = _size/300;
    attackRate = _size/30 * 50;
    range = oSprite.getGlobalBounds().width + oSprite.getGlobalBounds().width*0.5;
}
Black_Hole::~Black_Hole(){}

void Black_Hole::update(){
    if(animClock.getElapsedTime().asMilliseconds() > attackRate + 50){
        anim->play("hole");
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