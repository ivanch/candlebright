#include "Player.hpp"

Player::Player(int _template){
    health = 100;
    moveSpeed = 1.5;
    jumpHeight = 80;
    maxSlideX = 0.001;
    maxSlideY = 80;
    damage = 5.0;
    range = 20.0;
    attackSpeed = 10;
    finalJumpHeight = 0;

    anim = new AnimManager(&pSprite, {30,75});
    anim->addSheet("idle", "sprites/Player/idle.png");
    anim->addSheet("walk", "sprites/Player/walking.png");
    anim->addSheet("attack", "sprites/Player/new-Player-Attacking.png", 3);

    wSprite = sf::Sprite(*getTexture("sprites/Player/whip.png"));
    whipSize = 0.0;
    whipExpanding = true;

    healthBar = sf::Sprite(*getTexture("sprites/Player/health.png"));
    //healthBar.setScale(1/4, 1/4);

    setState(CharacterState::STATE_IDLE);
    facing = FACING_RIGHT;

    type = 0;

    if(_template == 1){
        key_right = sf::Keyboard::Right;
        key_left = sf::Keyboard::Left;
        key_jump = sf::Keyboard::Up;
        key_attack = sf::Keyboard::RControl;
        setPos({75.0, 600});
    }else{
        key_right = sf::Keyboard::D;
        key_left = sf::Keyboard::A;
        key_jump = sf::Keyboard::W;
        key_attack = sf::Keyboard::Z;
        setPos({50.0, 600});
    }
}
Player::~Player(){}

void Player::move(sf::Vector2f vec){
    if(vec.x > 0 && collidingRight) return;
    if(vec.x < 0 && collidingLeft) return;
    pSprite.move(vec);
}

void Player::setPos(sf::Vector2f newPos) {
    pSprite.setPosition(newPos);
}

void Player::moveRight(){
    if(anim->isLocked()) return;
    move({moveSpeed,0});
    setFacing(Character::FACING_RIGHT);
    setState(CharacterState::STATE_WALKING);
}

void Player::moveLeft(){
    if(anim->isLocked()) return;
    move({-moveSpeed,0});
    setFacing(Character::FACING_LEFT);
    setState(CharacterState::STATE_WALKING);
}

void Player::jump(){
    velocity.y -= 2.50;
    move({0,-2.50});
    setState(CharacterState::STATE_JUMPING);
}

void Player::update(){
    if(sf::Keyboard::isKeyPressed(key_right)) {
        if(velocity.x < maxSlideX)
            velocity.x += 10;
        if(velocity.x > maxSlideX) velocity.x = maxSlideX;
    }
    else if(sf::Keyboard::isKeyPressed(key_left)) {
        if(velocity.x > -maxSlideX)
            velocity.x -= 10;
        if(velocity.x < -maxSlideX) velocity.x = -maxSlideX;
    }
    else if(sf::Keyboard::isKeyPressed(key_jump) && !collidingUp && collidingDown){
        if(currentState->getState() != CharacterState::STATE_JUMPING){
            if(velocity.y < maxSlideY)
                velocity.y += jumpHeight;
            if(velocity.y > maxSlideY) velocity.y = maxSlideY;
            finalJumpHeight= (pSprite.getPosition().y) - jumpHeight;
        }
    }else if(sf::Keyboard::isKeyPressed(key_attack)){
        attack();
    }else{
        if(getState() != CharacterState::STATE_JUMPING)
            setState(CharacterState::STATE_IDLE);
    }

    if(velocity.x > 0.001){
        velocity.x -= 1 * abs(velocity.x*0.09);
        moveRight();
    }else if(velocity.x < -0.001){
        velocity.x += 1 * abs(velocity.x*0.09);
        moveLeft();
    }
    if(velocity.y > 0.001){
        jump();
    }
    if(pSprite.getPosition().y < finalJumpHeight + 5){
        setState(CharacterState::STATE_FALLING);
    }
    if(pSprite.getPosition().y > 800)
    {
        health -= 25;
        sf::Vector2f RespawnPos({50.0,600.0});
        setPos({RespawnPos.x,RespawnPos.y});
        if(health <= 0)
            std::exit(0);
    }

    if(collidingUp && getState() == CharacterState::STATE_JUMPING){
        velocity.y = 0;
        setState(CharacterState::STATE_FALLING);
    }

    if(currentState->getState() == CharacterState::STATE_WALKING){
        if(spriteClock.getElapsedTime().asMilliseconds() >= 150){
            spriteClock.restart();
            anim->play("walk");
        }
        if(facing == FACING_RIGHT){
            anim->setScale({1,1});
        }else{
            anim->setScale({-1,1});
        }
    }else if(currentState->getState() == CharacterState::STATE_ATTACKING){
        if(spriteClock.getElapsedTime().asMilliseconds() >= 150){
            spriteClock.restart();
            anim->play("attack", true);

            if(whipExpanding){
                whipSize += 5;
                if(whipSize >= range) whipExpanding = false;
            }else if(!whipExpanding){
                if(whipSize > 0) whipSize -= 5;
            }
        }
        wSprite.setScale({whipSize/range,1});
        wSprite.setPosition(pSprite.getPosition().x, pSprite.getPosition().y+10);
        //cout << whipSize << endl;
    }else{
        if(spriteClock.getElapsedTime().asMilliseconds() >= 150){
            spriteClock.restart();
            anim->play("idle");
        }
    }
}

void Player::draw(Engine* engine) {
    engine->draw(pSprite);
    if(whipSize > 0) engine->draw(wSprite);
    if(health > 0){
        int healthHearts = 25;
        for(int i = 1; i <= 100/healthHearts; i++){
            // 0..4
            if(health >= i*healthHearts){
                healthBar.setPosition(getPos().x - 45 - (15*(100/healthHearts - i)) + (20*i), getPos().y + 100);
                engine->draw(healthBar);
            }
        }
    }
}

void Player::fall(){
    if(currentState->getState() != CharacterState::STATE_JUMPING){
        move({0,2.50});
    }
}

sf::FloatRect Player::getRect(){
    return pSprite.getGlobalBounds();
}

void Player::attack(){
    if( currentState->getState() == CharacterState::STATE_ATTACKING ) return;
    setState(CharacterState::STATE_ATTACKING);
    whipExpanding = true;
    spriteClock.restart();
    anim->play("attack", true);
}

sf::Vector2f Player::getPos(){
    return pSprite.getPosition();
}

void Player::takeDamage(Character* issuer, float damage){
    health -= damage;
    move({0,-10});
    cout << "Levou dano" << endl;
}
