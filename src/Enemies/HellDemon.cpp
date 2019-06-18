#include "HellDemon.hpp"

HellDemon::HellDemon(sf::Vector2f pos, string _name){
    //eSprite.setSize({20,50});
    //eSprite.setFillColor(sf::Color::Red);
    setPos(pos);
    originalPos = pos;
    moveSpeed = 0.25;
    jumpHeight = 80;
    maxSlideX = 0.001;
    maxSlideY = 80;
    health = 100;
    damage = 5.0;
    range = 10.0;
    attackChance = 0.15 / 60; // 15%
    attackSpeed = 250;
    finalJumpHeight = 0;
    type = 1;

    setState(CharacterState::STATE_WALKING);
    facing = FACING_RIGHT;

    anim = new AnimManager(&eSprite, {45,60});
    anim->addSheet("walk", "sprites/Hell-Demon/new-hell-beast-idle.png");
    anim->addSheet("attack1", "sprites/Hell-Demon/new-hell-beast-burn.png");
    anim->addSheet("attack2", "sprites/Hell-Demon/new-hell-beast-breath.png", 3);
}
HellDemon::~HellDemon(){}

void HellDemon::move(sf::Vector2f vec){
    eSprite.move(vec);
}

void HellDemon::setPos(sf::Vector2f newPos) {
    eSprite.setPosition(newPos);
}

sf::Vector2f HellDemon::getPos(){
    return eSprite.getPosition();
}

void HellDemon::draw(Engine* engine) {
    engine->draw(eSprite);
}

sf::FloatRect HellDemon::getRect(){
    return eSprite.getGlobalBounds();
}
void HellDemon::fall(){
    if(currentState->getState() != CharacterState::STATE_JUMPING){
        move({0,2.50});
    }
}

void HellDemon::moveRight(){
    if(anim->isLocked()) return;
    move({moveSpeed,0});
    setFacing(Facing::FACING_RIGHT);
    setState(CharacterState::STATE_WALKING);
}

void HellDemon::moveLeft(){
    if(anim->isLocked()) return;
    move({-moveSpeed,0});
    setFacing(Facing::FACING_LEFT);
    setState(CharacterState::STATE_WALKING);
}

void HellDemon::update(){
    sf::Vector2f pos = eSprite.getPosition();
        
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
    if(collidingUp){
        velocity.y = 0;
        setState(CharacterState::STATE_FALLING);
    }

    if(((float) rand()) / (float) RAND_MAX <= attackChance && getState() == CharacterState::STATE_WALKING){
        attack();
    }
    
    if(getState() == CharacterState::STATE_ATTACKING){
        if(spriteClock.getElapsedTime().asMilliseconds() >= 200){
            spriteClock.restart();
            anim->play("attack1", true);
            if(anim->getCount() > 10){
                anim->stop();
            }
        }
    }else{
        if(spriteClock.getElapsedTime().asMilliseconds() >= 75){
            spriteClock.restart();
            anim->play("walk");
        }
        if(facing == FACING_RIGHT){
            anim->setScale({-1,1});
        }else{
            anim->setScale({1,1});
        }
    }
}

void HellDemon::takeDamage(Character* issuer, float damage){
    health -= damage;
    move({15,-5});
    if(health <= 0){
        cout << "Morreu" << endl;
        //delete this;
    }
}

void HellDemon::attack(){
    if(attackTimer.getElapsedTime().asSeconds() < 1/attackSpeed) return;
    setState(CharacterState::STATE_ATTACKING);

    anim->play("attack1", true);
    spriteClock.restart();
}