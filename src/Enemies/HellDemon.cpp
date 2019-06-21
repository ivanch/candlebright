#include "HellDemon.hpp"

Hell_Demon::Hell_Demon(sf::Vector2f pos){
    setPos(pos);
    originalPos = pos;
    moveSpeed = 0.25;
    jumpHeight = 80;
    maxSlideX = 0.001;
    maxSlideY = 80;
    finalJumpHeight = 0;
    type = 1;
    score = 3;

    health = 100;
    damage = 5.0;
    range = 10.0;
    attackChance = 0.15 / 60; // 15%
    attackSpeed = 250;

    setState(CharacterState::STATE_WALKING);
    facing = FACING_RIGHT;

    anim = new AnimManager(&eSprite, {45,60});
    anim->addSheet("walk", "sprites/Hell-Demon/new-hell-beast-idle.png");
    anim->addSheet("attack1", "sprites/Hell-Demon/new-hell-beast-burn.png");
    anim->addSheet("attack2", "sprites/Hell-Demon/new-hell-beast-breath.png", 3);
}
Hell_Demon::~Hell_Demon(){}

void Hell_Demon::move(sf::Vector2f vec){
    eSprite.move(vec);
}

void Hell_Demon::setPos(sf::Vector2f newPos) {
    eSprite.setPosition(newPos);
}

const sf::Vector2f Hell_Demon::getPos() const {
    return eSprite.getPosition();
}

const sf::FloatRect Hell_Demon::getRect() const {
    return eSprite.getGlobalBounds();
}
void Hell_Demon::fall(){
    if(currentState->getState() != CharacterState::STATE_JUMPING){
        move({0,2.50});
    }
}

void Hell_Demon::moveRight(){
    if(anim->isLocked()) return;
    move({moveSpeed,0});
    setFacing(Facing::FACING_RIGHT);
    setState(CharacterState::STATE_WALKING);
}

void Hell_Demon::moveLeft(){
    if(anim->isLocked()) return;
    move({-moveSpeed,0});
    setFacing(Facing::FACING_LEFT);
    setState(CharacterState::STATE_WALKING);
}

void Hell_Demon::update(){
    sf::Vector2f pos = eSprite.getPosition();

    if( getState() == CharacterState::STATE_FALLING && collidingDown ){
        setState(CharacterState::STATE_IDLE);
    }

    if(getState() == CharacterState::STATE_WALKING){
        if(facing == Facing::FACING_LEFT){
            if(!collidingLeft)
                moveLeft();
            else
                facing = Facing::FACING_RIGHT;
            if(abs(pos.x) < abs(originalPos.x-5)) facing = Facing::FACING_RIGHT;
        }else{
            if(!collidingRight)
                moveRight();
            else
                facing = Facing::FACING_LEFT;
            if(abs(pos.x) > abs(originalPos.x+5)) facing = Facing::FACING_LEFT;
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
        if(facing == FACING_RIGHT){
            anim->setScale({-1,1});
        }else{
            anim->setScale({1,1});
        }
    }

    if(getState() == CharacterState::STATE_IDLE) setState(CharacterState::STATE_WALKING);

    healthBar.setPos({getPos().x-25,getPos().y+60});
}

void Hell_Demon::draw(Engine& engine) {
    engine.draw(eSprite);
    healthBar.draw(engine);
}

void Hell_Demon::takeDamage(float _damage){
    health -= _damage;
    healthBar.setHealth(health);
    move({0,-1});
}

void Hell_Demon::attack(){
    setState(CharacterState::STATE_ATTACKING);

    anim->play("attack1", true);
    animClock.restart();
}
