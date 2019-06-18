#include "Ghost.hpp"

Ghost::Ghost(sf::Vector2f pos, string _name){
    //eSprite.setSize({20,50});
    //eSprite.setFillColor(sf::Color::Red);
    setPos(pos);
    originalPos = pos;
    moveSpeed = 0.5;
    jumpHeight = 80;
    maxSlideX = 0.001;
    maxSlideY = 80;
    health = 100;
    damage = 5.0;
    range = 10.0;
    attackChance = 0.15 / 60; // 15%
    attackSpeed = 0.5;
    finalJumpHeight = 0;
    type = 1;

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

sf::Vector2f Ghost::getPos(){
    return eSprite.getPosition();
}

void Ghost::draw(Engine* engine) {
    engine->draw(eSprite);
}

sf::FloatRect Ghost::getRect(){
    return eSprite.getGlobalBounds();
}
void Ghost::fall(){
    // Ghost não cai cai balão
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

    if(((float) rand()) / (float) RAND_MAX <= attackChance && getState() == CharacterState::STATE_WALKING){
        attack();
    }
    
    if(getState() == CharacterState::STATE_ATTACKING){
        if(spriteClock.getElapsedTime().asMilliseconds() >= 450){
            spriteClock.restart();
            anim->play("attack", true);
        }
    }else{
        if(spriteClock.getElapsedTime().asMilliseconds() >= 200){
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

void Ghost::takeDamage(Thing* issuer, float damage){
    health -= damage;
    move({15,-5});
    if(health <= 0){
        cout << "Morreu" << endl;
        //delete this;
    }
}

void Ghost::attack(){
    if(attackTimer.getElapsedTime().asSeconds() < 1/attackSpeed) return;
    setState(CharacterState::STATE_ATTACKING);
    anim->play("attack", true);
    spriteClock.restart();
}