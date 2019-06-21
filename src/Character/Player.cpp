#include "Player.hpp"

Player::Player(int _template){
    health = 100;
    moveSpeed = 1.5;
    jumpHeight = 100;
    maxSlideX = 0.001;
    maxSlideY = 100;
    damage = 5.0;
    range = 100.0;
    attackSpeed = 100;
    finalJumpHeight = 0;
    isDead = false;

    anim = new AnimManager(&pSprite, {30,75});
    anim->addSheet("idle", "sprites/Player/new-idle.png");
    anim->addSheet("walk", "sprites/Player/new-walking.png");
    anim->addSheet("jump", "sprites/Player/new-jumping.png", 4);
    anim->addSheet("attack", "sprites/Player/new-attacking.png", 3);

    wSprite = sf::Sprite(*getTexture("sprites/Player/whip.png"));
    whipSize = 0.0;
    whipExpanding = true;

    setState(CharacterState::STATE_IDLE);
    facing = FACING_RIGHT;

    type = 0;

    if(_template == 1){
        key_right = sf::Keyboard::Right;
        key_left = sf::Keyboard::Left;
        key_jump = sf::Keyboard::Up;
        key_attack = sf::Keyboard::Return;
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
    if(!setState(CharacterState::STATE_WALKING)) return;
    move({moveSpeed,0});
    setFacing(Character::FACING_RIGHT);
}

void Player::moveLeft(){
    if(anim->isLocked()) return;
    if(!setState(CharacterState::STATE_WALKING)) return;
    move({-moveSpeed,0});
    setFacing(Character::FACING_LEFT);
}

void Player::jump(){
    velocity.y -= 2.50;
    if(facing == FACING_RIGHT) move({0.5,-2.5});
    else move({-0.5,-2.5});
    setState(CharacterState::STATE_JUMPING);
}

void Player::update(){
    if(isDead) return;

    /* Gerencia os botões apertados */
    if(sf::Keyboard::isKeyPressed(key_right)) {
        if(velocity.x < maxSlideX)
            velocity.x += 10;
        if(velocity.x > maxSlideX) velocity.x = maxSlideX;
    }else if(sf::Keyboard::isKeyPressed(key_left)) {
        if(velocity.x > -maxSlideX)
            velocity.x -= 10;
        if(velocity.x < -maxSlideX) velocity.x = -maxSlideX;
    }else if(sf::Keyboard::isKeyPressed(key_jump) && !collidingUp && collidingDown){
        if(currentState->getState() != CharacterState::STATE_JUMPING){
            if(velocity.y < maxSlideY)
                velocity.y += jumpHeight;
            if(velocity.y > maxSlideY) velocity.y = maxSlideY;
            finalJumpHeight = (pSprite.getPosition().y) - jumpHeight;
        }
    }else if(sf::Keyboard::isKeyPressed(key_attack)){
        attack();
    }else{
        if(getState() != CharacterState::STATE_JUMPING)
            setState(CharacterState::STATE_IDLE);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
        std::cout << isCollidingLeft() << ", " << isCollidingUp() << ", " << isCollidingDown() << ", " << isCollidingRight() << std::endl;
    }

    /* Gerencia o estado do jogador */
    if(pSprite.getPosition().y < finalJumpHeight + 15 || collidingLeft || collidingRight){
        setState(CharacterState::STATE_FALLING);
        velocity.y = 0;
    }

    if(getState() == CharacterState::STATE_FALLING && collidingDown){
        setState(CharacterState::STATE_IDLE);
        velocity.y = 0;
    }

    if(getState() == CharacterState::STATE_JUMPING && (collidingLeft || collidingRight)){
        setState(CharacterState::STATE_FALLING);
        velocity.y = 0;
    }else if(getState() == CharacterState::STATE_JUMPING && collidingUp){
        setState(CharacterState::STATE_FALLING);
        velocity.y = 0;
    }

    /* Gerencia a movimentação do jogador */
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

    if(pSprite.getPosition().y > 800)
    {
        health -= 25;
        sf::Vector2f respawnPos({50.0,600.0});
        setPos({respawnPos.x,respawnPos.y});
        if(health <= 0)
            std::exit(0);
    }

    /* Gerenciar animações */
    switch (currentState->getState()){
        case CharacterState::STATE_WALKING:
            if(animClock.getElapsedTime().asMilliseconds() >= 150){
                animClock.restart();
                anim->play("walk");
                if(!anim->isLocked()){
                    setState(CharacterState::STATE_FALLING);
                }
            }
            if(facing == FACING_RIGHT){
                anim->setScale({1,1});
            }else{
                anim->setScale({-1,1});
            }
            break;
        case CharacterState::STATE_JUMPING:
            if(animClock.getElapsedTime().asMilliseconds() >= 50){
                animClock.restart();
                anim->play("jump");
            }
            if(facing == FACING_RIGHT){
                anim->setScale({1,1});
            }else{
                anim->setScale({-1,1});
            }
            break;
        case CharacterState::STATE_ATTACKING:
            if(animClock.getElapsedTime().asMilliseconds() >= 50){
                animClock.restart();
                anim->play("attack", true);
            }

            if(whipExpanding){
                whipSize += 5;
                if(whipSize >= range) whipExpanding = false;
            }else if(!whipExpanding){
                if(whipSize > 0) whipSize -= 5;
            }
    
            if(anim->isLocked()){
                if(facing == FACING_RIGHT)
                    wSprite.setScale({whipSize/range,1});
                else wSprite.setScale({-whipSize/range,1});
                wSprite.setPosition(pSprite.getPosition().x+5, pSprite.getPosition().y+15);
            }else{ // Acabou animação do ataque
                anim->stop();
                whipSize = 0;
                setState(CharacterState::STATE_IDLE);
            }
            break;
        default:
            if(animClock.getElapsedTime().asMilliseconds() >= 150){
                animClock.restart();
                anim->play("idle");
            }
            break;
    }

    healthBar.setPos({getPos().x-25,getPos().y+75});
    if(Enemy::enemyCount == 1){
        range = 200;
    }
}

void Player::draw(Engine& engine) {
    engine.draw(pSprite);
    if(whipSize > 0) engine.draw(wSprite);
    healthBar.draw(engine);
}

void Player::fall(){
    if(currentState->getState() != CharacterState::STATE_JUMPING){
        move({0,2.50});
    }
}

const sf::FloatRect Player::getRect() const {
    return pSprite.getGlobalBounds();
}

void Player::attack(){
    if(anim->isLocked()) return;
    if(!setState(CharacterState::STATE_ATTACKING)) return;
    whipExpanding = true;
    animClock.restart();
    anim->play("attack", true);
}

const sf::Vector2f Player::getPos() const {
    return pSprite.getPosition();
}

void Player::takeDamage(float _damage){
    health -= damage;
    healthBar.setHealth(health);
    move({0, -0.1});
    std::cout << "Levou dano" << std::endl;
}

void Player::death(){
    isDead = true;
}
