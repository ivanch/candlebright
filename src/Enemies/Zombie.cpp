#include "Zombie.hpp"

Zombie::Zombie(sf::Vector2f pos){
    setPos(pos);
    originalPos = pos;
    moveSpeed = 1.5;
    jumpHeight = 80;
    maxSlideX = 0.001;
    maxSlideY = 80;
    health = 100;
    damage = 5.0;
    range = 10.0;
    attackChance = 0.1 / 60; // Chance de ataques por segundo
    attackSpeed = 0.5;
    finalJumpHeight = 0;
    type = 1;

    setState(CharacterState::STATE_IDLE);
    facing = FACING_RIGHT;

    anim = new AnimManager(&eSprite, {20,50});
    anim->addSheet("walk", "sprites/Zombie/new-zombie-walking.png");

    healthBar.setSize({40.0,5});
}
Zombie::~Zombie(){}

void Zombie::move(sf::Vector2f vec){
    eSprite.move(vec);
}

void Zombie::setPos(sf::Vector2f newPos) {
    eSprite.setPosition(newPos);
}

sf::Vector2f Zombie::getPos(){
    return eSprite.getPosition();
}

sf::FloatRect Zombie::getRect(){
    return eSprite.getGlobalBounds();
}
void Zombie::fall(){
    if(currentState->getState() != CharacterState::STATE_JUMPING){
        move({0,2.50});
    }
}

void Zombie::moveRight(){
    move({moveSpeed,0});
    setFacing(Facing::FACING_RIGHT);
    setState(CharacterState::STATE_WALKING);
}

void Zombie::moveLeft(){
    move({-moveSpeed,0});
    setFacing(Facing::FACING_LEFT);
    setState(CharacterState::STATE_WALKING);
}

void Zombie::update(){
    sf::Vector2f pos = eSprite.getPosition();

    if(getState() == CharacterState::STATE_FALLING && collidingDown){
        setState(CharacterState::STATE_IDLE);
    }

    if(getState() == CharacterState::STATE_JUMPING && collidingUp){
        velocity.y = 0;
        setState(CharacterState::STATE_FALLING);
    }

    if(currentState->getState() == CharacterState::STATE_WALKING){
        if(facing == Facing::FACING_LEFT){
            if(!collidingLeft)
                moveLeft();
            else
                facing = Facing::FACING_RIGHT;
            if(abs(pos.x) < abs(originalPos.x-100)) facing = Facing::FACING_RIGHT;
        }else{
            if(!collidingRight)
                moveRight();
            else
                facing = Facing::FACING_LEFT;
            if(abs(pos.x) > abs(originalPos.x+100)) facing = Facing::FACING_LEFT;
        }

        if(animClock.getElapsedTime().asMilliseconds() >= 150){
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

void Zombie::draw(Engine* engine) {
    engine->draw(eSprite);
    healthBar.draw(engine);
}

void Zombie::takeDamage(Thing* _issuer, float _damage){
    health -= damage;
    healthBar.setHealth(health);
    move({0,-1});
    moveSpeed += moveSpeed * 0.05;
}

void Zombie::attack(){
    /* Zumbi não ataca, é mais ou menos um obstáculo */
}