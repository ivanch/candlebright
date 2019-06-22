#include "DressedZombie.hpp"

Dressed_Zombie::Dressed_Zombie(sf::Vector2f pos) {
    setPos(pos);
    originalPos = pos;
    moveSpeed = 1.5f;
    jumpHeight = 80.0f;
    maxSlideX = 0.001f;
    maxSlideY = 80.0f;
    finalJumpHeight = 0.0f;
    type = 1;
    score = 2;

    health = 150.0f;
    damage = 1.5f;
    range = 50.0f;
    attackChance = 0.25f / 60.0f; // 50%
    attackSpeed = 500.0f;

    setState(CharacterState::STATE_IDLE);
    setFacingRight();

    anim = new AnimManager(&eSprite, sf::Vector2i(20, 50));
    anim->addSheet("walk", "sprites/Clothed-Zombie/new-clothed-zombie-walking.png");

    healthBar.setSize(sf::Vector2f(40.0f, 5.0f));
    healthBar.setMaxHealth(health);
}
Dressed_Zombie::~Dressed_Zombie(){}

void Dressed_Zombie::move(sf::Vector2f vec){
    eSprite.move(vec);
}

void Dressed_Zombie::setPos(sf::Vector2f newPos) {
    eSprite.setPosition(newPos);
}

const sf::Vector2f Dressed_Zombie::getPos() const {
    return eSprite.getPosition();
}

const sf::FloatRect Dressed_Zombie::getRect() const {
    return eSprite.getGlobalBounds();
}
void Dressed_Zombie::fall(){
    if(getState() != CharacterState::STATE_JUMPING){
        move(sf::Vector2f(0, 2.50));
    }
}

void Dressed_Zombie::moveRight(){
    move(sf::Vector2f(moveSpeed, 0));
    setFacingRight();
    setState(CharacterState::STATE_WALKING);
}

void Dressed_Zombie::moveLeft(){
    move(sf::Vector2f(-moveSpeed, 0));
    setFacingRight(false);
    setState(CharacterState::STATE_WALKING);
}

void Dressed_Zombie::update(){
    sf::Vector2f pos = eSprite.getPosition();

    if(((float) rand()) / (float) RAND_MAX <= attackChance){
        attack();
    }

    if( getState() == CharacterState::STATE_FALLING && collidingDown ){
        setState(CharacterState::STATE_IDLE);
    }

    if(collidingUp){
        velocity.y = 0;
        setState(CharacterState::STATE_FALLING);
    }

    if(getState() == CharacterState::STATE_WALKING){
        if(!isFacingRight()){
            if(!collidingLeft)
                moveLeft();
            else
                setFacingRight();
            if(abs(pos.x) < abs(originalPos.x-150)) setFacingRight();
        }else{
            if(!collidingRight)
                moveRight();
            else
                setFacingRight(false);
            if(abs(pos.x) > abs(originalPos.x+150)) setFacingRight(false);
        }

        if(animClock.getElapsedTime().asMilliseconds() >= 125){
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

void Dressed_Zombie::draw(Engine& engine) {
    engine.draw(eSprite);
    healthBar.draw(engine);
}

void Dressed_Zombie::takeDamage(float _damage){
    health -= _damage;
    healthBar.setHealth(health);
    move(sf::Vector2f(0.f, -1.f));
    moveSpeed -= moveSpeed * 0.05;
}

void Dressed_Zombie::attack(){
    setState(CharacterState::STATE_ATTACKING);
    animClock.restart();
}
