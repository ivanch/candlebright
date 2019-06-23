#include "Ghost.hpp"

Ghost::Ghost(sf::Vector2f pos){
    setPosition(pos);
    originalPos = pos;
    moveSpeed = 0.5f;
    jumpHeight = 80.0f;
    maxSlideX = 0.001f;
    maxSlideY = 80.0f;
    finalJumpHeight = 0.0f;
    type = 1;
    score = 4;

    health = 100.0f;
    damage = 5.0f;
    range = 10.0f;
    attackChance = 0.15f / 60.0f; // 15%
    attackSpeed = 250.0f;

    setState(CharacterState::STATE_WALKING);
    setFacingRight();

    anim = new AnimManager(&eSprite, sf::Vector2i(35, 60));
    anim->addSheet("walk", "sprites/Ghost/new-ghost-idle.png");
    anim->addSheet("attack", "sprites/Ghost/new-ghost-shriek.png", 3);
}
Ghost::~Ghost(){ }

void Ghost::move(const sf::Vector2f& _move){
    eSprite.move(_move);
}

void Ghost::setPosition(sf::Vector2f _pos){
    eSprite.setPosition(_pos);
}

const sf::Vector2f Ghost::getPosition() const {
    return eSprite.getPosition();
}

const sf::FloatRect Ghost::getRect() const {
    return eSprite.getGlobalBounds();
}
void Ghost::fall(){
    move(sf::Vector2f(0, 0.05));
}

void Ghost::moveRight(){
    if(anim->isLocked()) return;
    move(sf::Vector2f(moveSpeed, 0));
    setFacingRight();
    setState(CharacterState::STATE_WALKING);
}

void Ghost::moveLeft(){
    if(anim->isLocked()) return;
    move(sf::Vector2f(-moveSpeed, 0));
    setFacingRight(false);
    setState(CharacterState::STATE_WALKING);
}

void Ghost::update(){
    sf::Vector2f pos = eSprite.getPosition();

    if(getState() == CharacterState::STATE_WALKING){
        if(!isFacingRight()){
            if(!collidingLeft)
                moveLeft();
            else
                setFacingRight();
            if(abs(pos.x) < abs(originalPos.x-30)) setFacingRight();
        }else{
            if(!collidingRight)
                moveRight();
            else
                setFacingRight(false);
            if(abs(pos.x) > abs(originalPos.x+30)) setFacingRight(false);
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
        if(isFacingRight()){
            anim->setScale(sf::Vector2f(-1.f, 1.f));
        }else{
            anim->setScale(sf::Vector2f(1.f, 1.f));
        }
    }

    if(getState() == CharacterState::STATE_IDLE) setState(CharacterState::STATE_WALKING);

    healthBar.setPosition(sf::Vector2f(getPosition().x-25, getPosition().y+60));
}

void Ghost::draw(Engine& engine) const  {
    engine.draw(eSprite);
    healthBar.draw(engine);
}

void Ghost::takeDamage(const float& _damage){
    health -= _damage;
    healthBar.setHealth(health);
    move(sf::Vector2f(0.0f, -1.f));
}

void Ghost::attack(){
    if(attackTimer.getElapsedTime().asSeconds() < 1/attackSpeed) return;
    setState(CharacterState::STATE_ATTACKING);
    anim->play("attack", true);
    animClock.restart();
}
