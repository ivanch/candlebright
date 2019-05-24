#include "Enemy.hpp"

vector<Enemy*> Enemy::enemies;

Enemy::Enemy(sf::Vector2f pos, string _name):
        name(_name){

    enemy.setSize({20,30});
    enemy.setFillColor(sf::Color::Red);
    setPos(pos);
    world = NULL;
    moveSpeed = 1.5;
    jumpHeight = 80;
    maxSlideX = 0.001;
    maxSlideY = 80;
    isJumping = false;
    health = 100;
    mRight = false;
    originalPos = (enemy.getPosition());
    finalJumpHeight = 0;
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
void Enemy::moveRight(){
    move({moveSpeed,0});
}
void Enemy::moveLeft(){
    move({-moveSpeed,0});
}
void Enemy::onUpdate(){

    sf::Vector2f pos = enemy.getPosition();
    
    if(mRight){
        if(!Engine::intersectsLeft(getRect()))
            enemy.move({-moveSpeed,0});
        else
            mRight=false;
        if(abs(pos.x) < abs(originalPos.x-100)) mRight = false;
    }else{
        if(!Engine::intersectsRight(getRect()))
            enemy.move({moveSpeed,0});
        else
            mRight=true;
        if(abs(pos.x) > abs(originalPos.x+100)) mRight = true;
    }
    if(Engine::intersectsUp(getRect())){
        velocity.y = 0;
        isJumping = false;
    }
}

void Enemy::takeDamage(float damage){
    health -= damage;
    move({15,0});
    if(health <= 0){
        for(int i = 0; i < enemies.size(); i++){
            if(enemies[i] == this){
                enemies.erase(enemies.begin()+i);
            }
        }
        for(int i = 0; i < Listener::listeners.size(); i++){
            if(Listener::listeners[i] == this){
                Listener::listeners.erase(listeners.begin()+i);
            }
        }
    }
}