#include "Zombie.hpp"

Zombie::Zombie(sf::Vector2f pos){
    setPos(pos);
    originalPos = pos;
    moveSpeed = 1.5f;
    jumpHeight = 80.0f;
    maxSlideX = 0.001f;
    maxSlideY = 80.0f;
    finalJumpHeight = 0.0f;
    type = 1;
    score = 1;

    health = 100.0f;
    damage = 5.0f;
    range = 50.0f;
    attackChance = 0.25f / 60.0f; // 25%
    attackSpeed = 250.0f;

    setState(CharacterState::STATE_IDLE);
    setFacingRight();

    anim = new AnimManager(&eSprite, sf::Vector2i(20, 50));
    anim->addSheet("walk", "sprites/Zombie/new-zombie-walking.png");

    healthBar.setSize(sf::Vector2f(40.0f, 5));
}
Zombie::~Zombie(){}

void Zombie::move(sf::Vector2f vec){
    eSprite.move(vec);
}

void Zombie::setPos(sf::Vector2f newPos) {
    eSprite.setPosition(newPos);
}

const sf::Vector2f Zombie::getPos() const {
    return eSprite.getPosition();
}

const sf::FloatRect Zombie::getRect() const {
    return eSprite.getGlobalBounds();
}
void Zombie::fall(){
    if(getState() != CharacterState::STATE_JUMPING){
        move(sf::Vector2f(0, 2.50));
    }
}

void Zombie::moveRight(){
    move(sf::Vector2f(moveSpeed, 0));
    setFacingRight();
    setState(CharacterState::STATE_WALKING);
}

void Zombie::moveLeft(){
    move(sf::Vector2f(-moveSpeed, 0));
    setFacingRight(false);
    setState(CharacterState::STATE_WALKING);
}

void Zombie::update(){
    sf::Vector2f pos = eSprite.getPosition();

    if(((float) rand()) / (float) RAND_MAX <= attackChance && getState() == CharacterState::STATE_WALKING){
        attack();
    }

    if(getState() == CharacterState::STATE_FALLING && collidingDown){
        setState(CharacterState::STATE_IDLE);
    }

    if(getState() == CharacterState::STATE_JUMPING && collidingUp){
        velocity.y = 0;
        setState(CharacterState::STATE_FALLING);
    }

    if(getState() == CharacterState::STATE_WALKING){
        if(!isFacingRight()){
            if(!collidingLeft)
                moveLeft();
            else
                setFacingRight();
            if(abs(pos.x) < abs(originalPos.x-100)) setFacingRight();
        }else{
            if(!collidingRight)
                moveRight();
            else
                setFacingRight(false);
            if(abs(pos.x) > abs(originalPos.x+100)) setFacingRight(false);
        }

        if(animClock.getElapsedTime().asMilliseconds() >= 150){
            animClock.restart();
            anim->play("walk");
        }
        if(isFacingRight()){
            anim->setScale(sf::Vector2f(-1.f, 1.f));
        }else{
            anim->setScale(sf::Vector2f(1.f, 1.f));
        }
    }else if(getState() == CharacterState::STATE_ATTACKING){
        if(animClock.getElapsedTime().asMilliseconds() >= 500){
            setState(CharacterState::STATE_IDLE);
        }
    }

    if(getState() == CharacterState::STATE_IDLE) setState(CharacterState::STATE_WALKING);

    healthBar.setPos(sf::Vector2f(getPos().x-20, getPos().y+50));
}

void Zombie::draw(Engine& engine) {
    engine.draw(eSprite);
    healthBar.draw(engine);
}

void Zombie::takeDamage(float _damage){
    health -= _damage;
    healthBar.setHealth(health);
    move(sf::Vector2f(0.f, -1.f));
    moveSpeed += moveSpeed * 0.05;
}

void Zombie::attack(){
    setState(CharacterState::STATE_ATTACKING);
    animClock.restart();
}
