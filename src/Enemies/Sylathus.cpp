#include "Sylathus.hpp"

Sylathus::Sylathus(sf::Vector2f pos): breathAnim(&bSprite, {160,96}){
    setPos(pos);
    originalPos = pos;
    moveSpeed = 2.5;
    jumpHeight = 80;
    maxSlideX = 0.001;
    maxSlideY = 80;
    health = 400;
    finalJumpHeight = 0;

    setState(CharacterState::STATE_IDLE);
    facing = FACING_RIGHT;
    type = 2;
    attackChance = 0.1 / 60; // 10%

    anim = new AnimManager(&sSprite, {170,120});
    anim->addSheet("idle","sprites/Sylathus/new-demon-idle.png");
    anim->addSheet("attack","sprites/Sylathus/new-demon-attack.png", 2);

    breathAnim.addSheet("blue", "sprites/Sylathus/breath-blue.png", 4);
}
Sylathus::~Sylathus(){}

void Sylathus::move(sf::Vector2f vec){
    sSprite.move(vec);
}

void Sylathus::setPos(sf::Vector2f newPos) {
    sSprite.setPosition(newPos);
}

sf::Vector2f Sylathus::getPos(){
    return sSprite.getPosition();
}

void Sylathus::draw(Engine* engine) {
    engine->draw(sSprite);
    if(breathAnim.isLocked()) engine->draw(bSprite);
}

sf::FloatRect Sylathus::getRect(){
    return sSprite.getGlobalBounds();
}

void Sylathus::fall(){
    // Sylathus não cai!
}

void Sylathus::moveRight(){
    move({moveSpeed,0});
}

void Sylathus::moveLeft(){
    move({-moveSpeed,0});
}

void Sylathus::update(){
    if(((float) rand()) / (float) RAND_MAX <= attackChance && getState() == CharacterState::STATE_IDLE){
        attack();
    }

    if(getState() == CharacterState::STATE_IDLE){
        if(spriteClock.getElapsedTime().asMilliseconds() >= 150){
            spriteClock.restart();
            anim->play("idle");
        }
    }else if(getState() == CharacterState::STATE_ATTACKING){
        if(spriteClock.getElapsedTime().asMilliseconds() >= 200){
            spriteClock.restart();
            anim->play("attack");
            if(anim->getCount() >= 8){
                if(breathClock.getElapsedTime().asMilliseconds() >= 250){
                    breathAnim.play("blue", true);
                    breathClock.restart();
                }
            }
            if(anim->getCount() >= 20){
                setState(CharacterState::STATE_IDLE);
                breathAnim.stop();
            }
        }
    }
}

void Sylathus::takeDamage(Character* issuer, float damage){
    health -= damage;
    move({15,-5});
    if(health <= 0){
        cout << "Morreu" << endl;
        //this->~Sylathus();
    }
}

void Sylathus::attack(){
    if(attackTimer.getElapsedTime().asSeconds() < 1/attackSpeed) return;
    setState(CharacterState::STATE_ATTACKING);
    attackTimer.restart();

    bSprite.setPosition(sSprite.getPosition().x-50, sSprite.getPosition().y+75);
    
    cout << "Sylathus atacou!" << endl;
}