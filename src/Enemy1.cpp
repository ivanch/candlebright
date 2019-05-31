#include "Enemy1.hpp"

Enemy_1::Enemy_1(sf::Vector2f pos, string _name){
    enemy.setSize({20,30});
    enemy.setFillColor(sf::Color::Red);
    setPos(pos);
    originalPos = pos;
    moveSpeed = 1.5;
    jumpHeight = 80;
    maxSlideX = 0.001;
    maxSlideY = 80;
    isJumping = false;
    health = 100;
    mLeft = false;
    finalJumpHeight = 0;
}
Enemy_1::~Enemy_1(){}

void Enemy_1::move(sf::Vector2f vec){
    enemy.move(vec);
}

void Enemy_1::setPos(sf::Vector2f newPos) {
    enemy.setPosition(newPos);
}

sf::Vector2f Enemy_1::getPos(){
    return enemy.getPosition();
}

void Enemy_1::draw() {
    engine->draw(enemy);
}

sf::FloatRect Enemy_1::getRect(){
    return enemy.getGlobalBounds();
}
void Enemy_1::fall(){
    if(!isJumping){
        move({0,2.50});
    }
}

void Enemy_1::moveRight(){
    move({moveSpeed,0});
}

void Enemy_1::moveLeft(){
    move({-moveSpeed,0});
}

void Enemy_1::update(){
    sf::Vector2f pos = enemy.getPosition();
    
    if(mLeft){
        if(!ColisionManager::intersectsLeft(getRect()))
            enemy.move({-moveSpeed,0});
        else
            mLeft=false;
        if(abs(pos.x) < abs(originalPos.x-100)) mLeft = false;
    }else{
        if(!ColisionManager::intersectsRight(getRect()))
            enemy.move({moveSpeed,0});
        else
            mLeft=true;
        if(abs(pos.x) > abs(originalPos.x+100)) mLeft = true;
    }
    if(ColisionManager::intersectsUp(getRect())){
        velocity.y = 0;
        isJumping = false;
    }
    draw();
}

void Enemy_1::takeDamage(float damage){
    health -= damage;
    move({15,-5});
    if(health <= 0){
        cout << "Morreu" << endl;
        this->~Enemy_1();
    }
}