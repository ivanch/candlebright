#include "Boss.hpp"

Boss::Boss(sf::Vector2f pos, string _name){
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
Boss::~Boss(){}

void Boss::move(sf::Vector2f vec){
    enemy.move(vec);
}

void Boss::setPos(sf::Vector2f newPos) {
    enemy.setPosition(newPos);
}

sf::Vector2f Boss::getPos(){
    return enemy.getPosition();
}

void Boss::draw(Engine* engine) {
    engine->draw(enemy);
}

sf::FloatRect Boss::getRect(){
    return enemy.getGlobalBounds();
}
void Boss::fall(){
    if(!isJumping){
        move({0,2.50});
    }
}

void Boss::moveRight(){
    move({moveSpeed,0});
}

void Boss::moveLeft(){
    move({-moveSpeed,0});
}

void Boss::update(){
    sf::Vector2f pos = enemy.getPosition();
    
    if(mLeft){
        if(!collidingLeft)
            enemy.move({-moveSpeed,0});
        else
            mLeft=false;
        if(abs(pos.x) < abs(originalPos.x-100)) mLeft = false;
    }else{
        if(!collidingRight)
            enemy.move({moveSpeed,0});
        else
            mLeft=true;
        if(abs(pos.x) > abs(originalPos.x+100)) mLeft = true;
    }
    if(collidingUp){
        velocity.y = 0;
        isJumping = false;
    }
}

void Boss::takeDamage(float damage){
    health -= damage;
    move({15,-5});
    if(health <= 0){
        cout << "Morreu" << endl;
        this->~Boss();
    }
}

void Boss::attack(){
    // to-do
}