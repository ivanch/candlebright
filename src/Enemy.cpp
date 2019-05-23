#include "Enemy.hpp"

vector<Enemy*> Enemy::enemies;

Enemy::Enemy(sf::Vector2f pos, string _name):
        name(_name){

    enemy.setSize({20,30});
    enemy.setFillColor(sf::Color::Red);
    setPos(pos);
    world = NULL;
    isJumping = false;
    health = 100;
    enemies.push_back(this);
}
Enemy::~Enemy(){
    for(int i = 0; i < enemies.size(); i++)
        if(enemies[i] == this) enemies.erase(enemies.begin()+i);
}

void Enemy::move(sf::Vector2f vec){
    enemy.move(vec);
}
void Enemy::setPos(sf::Vector2f newPos) {
    enemy.setPosition(newPos);
}
sf::Vector2f Enemy::getPos(){
    return enemy.getPosition();
}

void Enemy::drawTo(sf::RenderWindow &window) {
    window.draw(enemy);
}
sf::FloatRect Enemy::getRect(){
    return enemy.getGlobalBounds();
}
void Enemy::fall(){
    if(!isJumping){
        move({0,2.50});
    }
}
void Enemy::onUpdate(){
    if(Engine::intersectsUp(getRect())){
        velocity.y = 0;
        isJumping = false;
    }
}

void Enemy::takeDamage(float damage){
    health -= damage;
    move({15,0});
    if(health <= 0){
        for(int i = 0; i < enemies.size(); i++)
            if(enemies[i] == this) enemies.erase(enemies.begin()+i);
    }
}