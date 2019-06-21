#include "Enemy.hpp"

unsigned int Enemy::enemyCount = 0;

Enemy::Enemy(){
    enemyCount++;
    score = 0;
}
Enemy::~Enemy(){
    enemyCount--;
    Player::setScore(Player::getScore()+score);
}

void Enemy::setPos(sf::Vector2f _pos){
    eSprite.setPosition(_pos);
}

const sf::Vector2f Enemy::getPos(){
    return eSprite.getPosition();
}
