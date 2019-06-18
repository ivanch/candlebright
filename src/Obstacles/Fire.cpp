#include "Fire.hpp"

Fire::Fire(sf::Vector2f pos, float _size){
    oSprite.setPosition(pos);
    position = pos;
    type = 1;

    anim = new AnimManager(&oSprite, {20,60});
    anim->addSheet("fire", "sprites/Obstacle/new-Fire.png");
    // Computa o ataque, taxa de ataque, dano e tamanho
    anim->setScale({_size/25, _size/30}); // Tamanho
    damage = _size/500;
    attackRate = _size/50 * 250;
    cout << damage << ", " << attackRate << endl;
}
Fire::~Fire(){}

void Fire::update(){
    if(animClock.getElapsedTime().asMilliseconds() > 200){
        anim->play("fire");
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