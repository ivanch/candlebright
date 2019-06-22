#include "Enemy.hpp"

unsigned int Enemy::enemyCount = 0;

Enemy::Enemy(): score(0) {
    enemyCount++;
}
Enemy::~Enemy(){
    enemyCount--;
    Player::setScore(Player::getScore()+score);
}

void Enemy::setPos(sf::Vector2f _pos){
    eSprite.setPosition(_pos);
}

const sf::Vector2f Enemy::getPos() const {
    return eSprite.getPosition();
}
