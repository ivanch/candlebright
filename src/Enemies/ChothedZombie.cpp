#include "ClothedZombie.hpp"

ClothedZombie::ClothedZombie(sf::Vector2f pos){
    setPos(pos);
    originalPos = pos;
    moveSpeed = 1.5;
    jumpHeight = 80;
    maxSlideX = 0.001;
    maxSlideY = 80;
    health = 150;
    damage = 5.0;
    range = 10.0;
    attackChance = 0.1 / 60; // Chance de ataques por segundo
    attackSpeed = 0.5;
    finalJumpHeight = 0;
    type = 1;

    setState(CharacterState::STATE_WALKING);
    facing = FACING_RIGHT;

    anim = new AnimManager(&eSprite, {20,50});
    anim->addSheet("walk", "sprites/Clothed-Zombie/new-clothed-zombie-walking.png");
}
ClothedZombie::~ClothedZombie(){}

void ClothedZombie::move(sf::Vector2f vec){
    eSprite.move(vec);
}

void ClothedZombie::setPos(sf::Vector2f newPos) {
    eSprite.setPosition(newPos);
}

sf::Vector2f ClothedZombie::getPos(){
    return eSprite.getPosition();
}

void ClothedZombie::draw(Engine* engine) {
    engine->draw(eSprite);
}

sf::FloatRect ClothedZombie::getRect(){
    return eSprite.getGlobalBounds();
}
void ClothedZombie::fall(){
    if(currentState->getState() != CharacterState::STATE_JUMPING){
        move({0,2.50});
    }
}

void ClothedZombie::moveRight(){
    move({moveSpeed,0});
    setFacing(Facing::FACING_RIGHT);
}

void ClothedZombie::moveLeft(){
    move({-moveSpeed,0});
    setFacing(Facing::FACING_LEFT);
}

void ClothedZombie::update(){
    sf::Vector2f pos = eSprite.getPosition();
    
    if(facing == Facing::FACING_LEFT){
        if(!collidingLeft)
            eSprite.move({-moveSpeed,0});
        else
            facing = Facing::FACING_RIGHT;
        if(abs(pos.x) < abs(originalPos.x-150)) facing = Facing::FACING_RIGHT;
    }else{
        if(!collidingRight)
            eSprite.move({moveSpeed,0});
        else
            facing = Facing::FACING_LEFT;
        if(abs(pos.x) > abs(originalPos.x+150)) facing = Facing::FACING_LEFT;
    }
    if(collidingUp){
        velocity.y = 0;
        setState(CharacterState::STATE_FALLING);
    }

    if(currentState->getState() == CharacterState::STATE_WALKING){
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
}

void ClothedZombie::takeDamage(Thing* _issuer, float _damage){
    health -= damage;
    move({15,-5});
    moveSpeed -= moveSpeed * 0.05;
    if(health <= 0){
        cout << "Morreu" << endl;
        //delete this;
    }
}

void ClothedZombie::attack(){
    /* Outro bichão que não ataca */
}