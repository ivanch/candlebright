#include "HellDemon.hpp"

Hell_Demon::Hell_Demon(sf::Vector2f pos){
    setPosition(pos);
    originalPos = pos;
    moveSpeed = 0.25;
    jumpHeight = 80.0f;
    maxSlideX = 0.001f;
    maxSlideY = 80.0f;
    finalJumpHeight = 0.0f;
    type = 1;
    score = 3;

    health = 250.0f;
    damage = 5.0f;
    range = 75.0f;
    attackChance = 0.15f / 60.0f; // 15%
    attackSpeed = 150.0f;

    setState(CharacterState::STATE_WALKING);
    setFacingRight();

    anim = new AnimManager(&eSprite, sf::Vector2i(45, 60));
    anim->addSheet("walk", "sprites/Hell-Demon/new-hell-beast-idle.png");
    anim->addSheet("attack1", "sprites/Hell-Demon/new-hell-beast-burn.png");
    anim->addSheet("attack2", "sprites/Hell-Demon/new-hell-beast-breath.png", 3);

    healthBar.setSize(sf::Vector2f(50.0f, 7.f));
    healthBar.setMaxHealth(health);
}
Hell_Demon::~Hell_Demon(){ }

void Hell_Demon::move(const sf::Vector2f& _move){
    eSprite.move(_move);
}

void Hell_Demon::setPosition(sf::Vector2f _pos){
    eSprite.setPosition(_pos);
}

const sf::Vector2f Hell_Demon::getPosition() const {
    return eSprite.getPosition();
}

const sf::FloatRect Hell_Demon::getRect() const {
    return eSprite.getGlobalBounds();
}
void Hell_Demon::fall(){
    if(getState() != CharacterState::STATE_JUMPING){
        move(sf::Vector2f(0, 2.50));
    }
}

void Hell_Demon::moveRight(){
    if(anim->isLocked()) return;
    move(sf::Vector2f(moveSpeed, 0));
    setFacingRight();
    setState(CharacterState::STATE_WALKING);
}

void Hell_Demon::moveLeft(){
    if(anim->isLocked()) return;
    move(sf::Vector2f(-moveSpeed, 0));
    setFacingRight(false);
    setState(CharacterState::STATE_WALKING);
}

void Hell_Demon::update(){
    sf::Vector2f pos = eSprite.getPosition();

    if( getState() == CharacterState::STATE_FALLING && collidingDown ){
        setState(CharacterState::STATE_IDLE);
    }

    if(getState() == CharacterState::STATE_WALKING){
        if(!isFacingRight()){
            if(!collidingLeft)
                moveLeft();
            else
                setFacingRight();
            if(abs(pos.x) < abs(originalPos.x-5)) setFacingRight();
        }else{
            if(!collidingRight)
                moveRight();
            else
                setFacingRight(false);
            if(abs(pos.x) > abs(originalPos.x+5)) setFacingRight(false);
        }
    }
    if(collidingUp){
        velocity.y = 0;
        setState(CharacterState::STATE_FALLING);
    }

    if(((float) rand()) / (float) RAND_MAX <= attackChance && getState() == CharacterState::STATE_WALKING){
        attack();
    }

    if(getState() == CharacterState::STATE_ATTACKING){
        if(animClock.getElapsedTime().asMilliseconds() >= 200){
            animClock.restart();
            anim->play("attack1", true);
            if(anim->getCount() > 10){
                anim->stop();
                setState(CharacterState::STATE_IDLE);
            }
        }
    }else if(getState() == CharacterState::STATE_WALKING){
        if(animClock.getElapsedTime().asMilliseconds() >= 75){
            animClock.restart();
            anim->play("walk");
        }
        if(isFacingRight()){
            anim->setScale(sf::Vector2f(-1.f, 1.f));
        }else{
            anim->setScale(sf::Vector2f(1.f, 1.f));
        }
    }

    if(getState() == CharacterState::STATE_IDLE) setState(CharacterState::STATE_WALKING);

    healthBar.setPosition(sf::Vector2f(getPosition().x-25, getPosition().y+60));
}

void Hell_Demon::draw(Engine& engine) const  {
    engine.draw(eSprite);
    healthBar.draw(engine);
}

void Hell_Demon::takeDamage(const float& _damage){
    health -= _damage;
    healthBar.setHealth(health);
    move(sf::Vector2f(0.0f, -1.f));
}

void Hell_Demon::attack(){
    setState(CharacterState::STATE_ATTACKING);

    anim->play("attack1", true);
    animClock.restart();
}
