#include "Enemy.hpp"

unsigned int Enemy::enemyCount = 0;

Enemy::Enemy(){
    enemyCount++;
}
Enemy::~Enemy(){
    enemyCount--;
}

void Enemy::setPos(sf::Vector2f _pos){
    eSprite.setPosition(_pos);
}

const sf::Vector2f Enemy::getPos(){
    return eSprite.getPosition();
}