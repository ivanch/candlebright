#include "Sylathus.hpp"

Sylathus::Sylathus(sf::Vector2f pos): breathAnim(&bSprite, sf::Vector2i(160, 96)){
    setPos(pos);
    originalPos = pos;
    moveSpeed = 2.5f;
    jumpHeight = 80.0f;
    maxSlideX = 0.001f;
    maxSlideY = 80.0f;
    finalJumpHeight = 0.0f;
    score = 10;
    type = 1;

    health = 500.0f;
    damage = 1.0f;
    range = 175.0f;
    attackChance = 0.1f / 60.0f; // 10%
    attackSpeed = 75.0f;
    preAttack = false;

    setState(CharacterState::STATE_IDLE);
    setFacingRight(false);

    anim = new AnimManager(&eSprite, sf::Vector2i(170, 120));
    anim->addSheet("idle","sprites/Sylathus/new-demon-idle.png");
    anim->addSheet("attack","sprites/Sylathus/new-demon-attack.png", 2);

    breathAnim.addSheet("blue", "sprites/Sylathus/breath-blue.png", 4);

    healthBar.setSize(sf::Vector2f(200.0f, 10.0f));
    healthBar.setMaxHealth(health);
}
Sylathus::~Sylathus(){}

void Sylathus::move(sf::Vector2f vec){
    eSprite.move(vec);
}

void Sylathus::setPos(sf::Vector2f newPos) {
    eSprite.setPosition(newPos);
}

const sf::Vector2f Sylathus::getPos() const {
    return eSprite.getPosition();
}

const sf::FloatRect Sylathus::getRect() const {
    return eSprite.getGlobalBounds();
}

void Sylathus::fall(){
    // Sylathus não cai!
}

void Sylathus::moveRight(){
    move(sf::Vector2f(moveSpeed, 0));
}

void Sylathus::moveLeft(){
    move(sf::Vector2f(-moveSpeed, 0));
}

void Sylathus::update(){
    if(((float) rand()) / (float) RAND_MAX <= attackChance && getState() == CharacterState::STATE_IDLE && preAttack == false){
        attack();
    }

    if(preAttack){
        if(animClock.getElapsedTime().asMilliseconds() >= 150){
            animClock.restart();
            anim->play("attack");
            if(anim->getCount() == 8){
                setState(CharacterState::STATE_ATTACKING);
                preAttack = false;
            }
        }
    }else if(getState() == CharacterState::STATE_IDLE){
        if(animClock.getElapsedTime().asMilliseconds() >= 150){
            animClock.restart();
            anim->play("idle");
        }
    }else if(getState() == CharacterState::STATE_ATTACKING){
        if(animClock.getElapsedTime().asMilliseconds() >= 150){
            animClock.restart();
            anim->play("attack");
            if(anim->getCount() >= 8){
                if(breathClock.getElapsedTime().asMilliseconds() >= 200){
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

    healthBar.setPos(sf::Vector2f(getPos().x-135, getPos().y+120));
}

void Sylathus::draw(Engine& engine) {
    engine.draw(eSprite);
    if(breathAnim.isLocked()) engine.draw(bSprite);
    healthBar.draw(engine);
}

void Sylathus::takeDamage(float _damage){
    health -= _damage;
    healthBar.setHealth(health);
}

void Sylathus::attack(){
    preAttack = true;
    bSprite.setPosition(eSprite.getPosition().x-50, eSprite.getPosition().y+75);
    attackTimer.restart();

    std::cout << "Sylathus atacou!" << std::endl;
}
