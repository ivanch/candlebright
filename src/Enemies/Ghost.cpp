#include "Ghost.hpp"

Ghost::Ghost(sf::Vector2f pos){
    setPos(pos);
    originalPos = pos;
    moveSpeed = 0.5;
    jumpHeight = 80;
    maxSlideX = 0.001;
    maxSlideY = 80;
    finalJumpHeight = 0;
    type = 1;
    score = 4;

    health = 100;
    damage = 5.0;
    range = 10.0;
    attackChance = 0.15 / 60; // 15%
    attackSpeed = 250;

    setState(CharacterState::STATE_WALKING);
    facing = FACING_RIGHT;

    anim = new AnimManager(&eSprite, {35,60});
    anim->addSheet("walk", "sprites/Ghost/new-ghost-idle.png");
    anim->addSheet("attack", "sprites/Ghost/new-ghost-shriek.png", 3);
}
Ghost::~Ghost(){}

void Ghost::move(sf::Vector2f vec){
    eSprite.move(vec);
}

void Ghost::setPos(sf::Vector2f newPos) {
    eSprite.setPosition(newPos);
}

const sf::Vector2f Ghost::getPos() const {
    return eSprite.getPosition();
}

const sf::FloatRect Ghost::getRect() const {
    return eSprite.getGlobalBounds();
}
void Ghost::fall(){
    move({0, 0.05});
}

void Ghost::moveRight(){
    if(anim->isLocked()) return;
    move({moveSpeed,0});
    setFacing(Facing::FACING_RIGHT);
    setState(CharacterState::STATE_WALKING);
}

void Ghost::moveLeft(){
    if(anim->isLocked()) return;
    move({-moveSpeed,0});
    setFacing(Facing::FACING_LEFT);
    setState(CharacterState::STATE_WALKING);
}

void Ghost::update(){
    sf::Vector2f pos = eSprite.getPosition();

    if(getState() == CharacterState::STATE_WALKING){
        if(facing == Facing::FACING_LEFT){
            if(!collidingLeft)
                moveLeft();
            else
                facing = Facing::FACING_RIGHT;
            if(abs(pos.x) < abs(originalPos.x-30)) facing = Facing::FACING_RIGHT;
        }else{
            if(!collidingRight)
                moveRight();
            else
                facing = Facing::FACING_LEFT;
            if(abs(pos.x) > abs(originalPos.x+30)) facing = Facing::FACING_LEFT;
        }
    }

    if(((float) rand()) / (float) RAND_MAX <= attackChance && getState() == CharacterState::STATE_WALKING){
        attack();
    }

    if(getState() == CharacterState::STATE_ATTACKING){
        if(animClock.getElapsedTime().asMilliseconds() >= 450){
            animClock.restart();
            anim->play("attack", true);
            if(anim->getCount() >= 4){
                anim->stop();
                setState(CharacterState::STATE_IDLE);
            }
        }
    }else{
        if(animClock.getElapsedTime().asMilliseconds() >= 200){
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

void Ghost::draw(Engine& engine) {
    engine.draw(eSprite);
    healthBar.draw(engine);
}

void Ghost::takeDamage(float _damage){
    health -= _damage;
    healthBar.setHealth(health);
    move({0,-1});
}

void Ghost::attack(){
    if(attackTimer.getElapsedTime().asSeconds() < 1/attackSpeed) return;
    setState(CharacterState::STATE_ATTACKING);
    anim->play("attack", true);
    animClock.restart();
}
