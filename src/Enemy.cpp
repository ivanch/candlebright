#include "Enemy.hpp"

vector<Enemy*> Enemy::enemies;

Enemy::Enemy(sf::Vector2f pos, string _name):
        name(_name){

    enemy.setSize({20,30});
    enemy.setFillColor(sf::Color::Red);
<<<<<<< HEAD
    setPos({170, 670});
=======
    setPos(pos);
>>>>>>> 61d677c6e43d27cdb3f7ee19925af9767dc84340
    world = NULL;
    vida = 100;
    moveSpeed = 1.5;
    jumpHeight = 80;
    maxSlideX = 0.001;
    maxSlideY = 80;
    isJumping = false;
<<<<<<< HEAD
    mRight = false;
    originalPos = (enemy.getPosition());
    finalJumpHeight = 0;
    Listener::listeners.push_back(dynamic_cast<Listener*>(this));
=======
    health = 100;
    enemies.push_back(this);
}
Enemy::~Enemy(){
    for(int i = 0; i < enemies.size(); i++)
        if(enemies[i] == this) enemies.erase(enemies.begin()+i);
>>>>>>> 61d677c6e43d27cdb3f7ee19925af9767dc84340
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
<<<<<<< HEAD

    sf::Vector2f pos = enemy.getPosition();

     if(mRight){
            if(!world->intersectsLeft(getRect()))
                enemy.move({-moveSpeed,0});
            else
                mRight=false;
            if(abs(pos.x) < abs(originalPos.x-100)) mRight = false;
        }else{
            if(!world->intersectsRight(getRect()))
                enemy.move({moveSpeed,0});
            else
                mRight=true;
            if(abs(pos.x) > abs(originalPos.x+100)) mRight = true;
        }
    if(world->intersectsUp(getRect())){
=======
    if(Engine::intersectsUp(getRect())){
>>>>>>> 61d677c6e43d27cdb3f7ee19925af9767dc84340
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