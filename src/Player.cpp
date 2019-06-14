#include "Player.hpp"

Player::Player(int _template):
        anim(&pSprite, {30,75}){

    health = 100;
    moveSpeed = 1.5;
    jumpHeight = 80;
    maxSlideX = 0.001;
    maxSlideY = 80;
    damage = 25.0;
    attackSpeed = 2;
    isJumping = false;
    finalJumpHeight = 0;

    anim.addSheet("idle", "sprites/Player/idle.png");
    anim.addSheet("walk", "sprites/Player/walking.png");

    isMovingRight = true;
    isMoving = false;

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
    isMoving = true;
}

void Player::setPos(sf::Vector2f newPos) {
    pSprite.setPosition(newPos);
}

void Player::moveRight(){
    move({moveSpeed,0});
    isMovingRight = true;
}

void Player::moveLeft(){
    move({-moveSpeed,0});
    isMovingRight = false;
}

void Player::jump(){
    velocity.y -= 2.50;
    move({0,-2.50});
    isJumping=true;
}

void Player::update(){
    isMoving = false;
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
        if(!isJumping){
            if(velocity.y < maxSlideY)
                velocity.y += jumpHeight;
            if(velocity.y > maxSlideY) velocity.y = maxSlideY;
            finalJumpHeight= (pSprite.getPosition().y) - jumpHeight;

        }
    }
    if(sf::Keyboard::isKeyPressed(key_attack)){
        attack();
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
    if(pSprite.getPosition().y < finalJumpHeight + 5)
        isJumping=false;
    if(pSprite.getPosition().y > 800)
    {
        health -= 25;
        sf::Vector2f RespawnPos({50.0,600.0});
        setPos({RespawnPos.x,RespawnPos.y});
        if(health <= 0)
            std::exit(0);
    }

    if(collidingUp){
        velocity.y = 0;
        isJumping = false;
    }
    if(isMoving){
        if(spriteClock.getElapsedTime().asMilliseconds() >= 150){
            spriteClock.restart();
            anim.play("walk");
        }
        if(isMovingRight){
            anim.setScale({1,1});
        }else{
            anim.setScale({-1,1});
        }
    }else{
        if(spriteClock.getElapsedTime().asMilliseconds() >= 150){
            spriteClock.restart();
            anim.play("idle");
        }
    }
}

void Player::draw(Engine* engine) {
    engine->draw(pSprite);
}

void Player::fall(){
    if(!isJumping){
        move({0,2.50});
    }
}

sf::FloatRect Player::getRect(){
    return pSprite.getGlobalBounds();
}

void Player::attack(){
    if(attackTimer.getElapsedTime().asSeconds() < 1/attackSpeed) return;
    attacking = true;
    attackTimer.restart();
}

sf::Vector2f Player::getPos(){
    return pSprite.getPosition();
}

void Player::takeDamage(Character* issuer, float damage){
    health -= damage;
    move({0,2});
    cout << "Levou dano" << endl;
}
