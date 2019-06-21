#include "DressedZombie.hpp"

Dressed_Zombie::Dressed_Zombie(sf::Vector2f pos){
    setPos(pos);
    originalPos = pos;
    moveSpeed = 1.5;
    jumpHeight = 80;
    maxSlideX = 0.001;
    maxSlideY = 80;
    finalJumpHeight = 0;
    type = 1;
    score = 2;

    health = 150;
    damage = 5.0;
    range = 10.0;
    attackChance = 0.1 / 60; // 10%
    attackSpeed = 200;

    setState(CharacterState::STATE_IDLE);
    facing = FACING_RIGHT;

    anim = new AnimManager(&eSprite, {20,50});
    anim->addSheet("walk", "sprites/Clothed-Zombie/new-clothed-zombie-walking.png");

    healthBar.setSize({40.0,5});
    healthBar.setMaxHealth(150);
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
    if(currentState->getState() != CharacterState::STATE_JUMPING){
        move({0,2.50});
    }
}

void Dressed_Zombie::moveRight(){
    move({moveSpeed,0});
    setFacing(Facing::FACING_RIGHT);
    setState(CharacterState::STATE_WALKING);
}

void Dressed_Zombie::moveLeft(){
    move({-moveSpeed,0});
    setFacing(Facing::FACING_LEFT);
    setState(CharacterState::STATE_WALKING);
}

void Dressed_Zombie::update(){
    sf::Vector2f pos = eSprite.getPosition();

    if( getState() == CharacterState::STATE_FALLING && collidingDown ){
        setState(CharacterState::STATE_IDLE);
    }

    if(collidingUp){
        velocity.y = 0;
        setState(CharacterState::STATE_FALLING);
    }

    if(currentState->getState() == CharacterState::STATE_WALKING){
        if(facing == Facing::FACING_LEFT){
            if(!collidingLeft)
                moveLeft();
            else
                facing = Facing::FACING_RIGHT;
            if(abs(pos.x) < abs(originalPos.x-150)) facing = Facing::FACING_RIGHT;
        }else{
            if(!collidingRight)
                moveRight();
            else
                facing = Facing::FACING_LEFT;
            if(abs(pos.x) > abs(originalPos.x+150)) facing = Facing::FACING_LEFT;
        }

        if(animClock.getElapsedTime().asMilliseconds() >= 125){
            animClock.restart();
            anim->play("walk");
        }
        if(facing == FACING_RIGHT){
            anim->setScale({-1,1});
        }else{
            anim->setScale({1,1});
        }
    }

    if(((float) rand()) / (float) RAND_MAX <= attackChance){
        attack();
    }

    if(getState() == CharacterState::STATE_IDLE) setState(CharacterState::STATE_WALKING);

    healthBar.setPos({getPos().x-20,getPos().y+50});
}

void Dressed_Zombie::draw(Engine& engine) {
    engine.draw(eSprite);
    healthBar.draw(engine);
}

void Dressed_Zombie::takeDamage(float _damage){
    health -= _damage;
    healthBar.setHealth(health);
    move({0,-1});
    moveSpeed -= moveSpeed * 0.05;
}

void Dressed_Zombie::attack(){
    /* Outro bichão que não ataca */
}
