#include "Player.hpp"

unsigned int Player::score = 0;

Player::Player(const int _template){
    health = 100;
    moveSpeed = 1.5;
    jumpHeight = 100;
    maxSlideX = 0.001;
    maxSlideY = 100;
    damage = 5.0f;
    range = 100.0f;
    attackSpeed = 100;
    finalJumpHeight = 0;
    score = 0;
    dead = false;

    anim = new AnimManager(&pSprite, sf::Vector2i(30, 75));
    anim->addSheet("idle", "sprites/Player/new-idle.png");
    anim->addSheet("walk", "sprites/Player/new-walking.png");
    anim->addSheet("jump", "sprites/Player/new-jumping.png", 4);
    anim->addSheet("attack", "sprites/Player/new-attacking.png", 3);
    anim->addSheet("dying", "sprites/Player/new-dying.png", 4);

    wSprite = sf::Sprite(*getTexture("sprites/Player/whip.png"));
    whipSize = 0.0f;
    whipExpanding = true;

    setState(CharacterState::STATE_IDLE);

    type = 0;

    if(_template == 1){
        key_right = sf::Keyboard::Right;
        key_left = sf::Keyboard::Left;
        key_jump = sf::Keyboard::Up;
        key_attack = sf::Keyboard::Return;
    }else{
        key_right = sf::Keyboard::D;
        key_left = sf::Keyboard::A;
        key_jump = sf::Keyboard::W;
        key_attack = sf::Keyboard::Z;
    }
}
Player::~Player(){ }

void Player::move(const sf::Vector2f& _move){
    if(_move.x > 0 && collidingRight) return;
    if(_move.x < 0 && collidingLeft) return;
    pSprite.move(_move);
}

void Player::setPosition(sf::Vector2f _pos){
    pSprite.setPosition(_pos);
}

void Player::moveRight(){
    if(anim->isLocked()) return;
    if(!setState(CharacterState::STATE_WALKING)) return;
    move(sf::Vector2f(moveSpeed, 0));
    setFacingRight();
}

void Player::moveLeft(){
    if(anim->isLocked()) return;
    if(!setState(CharacterState::STATE_WALKING)) return;
    move(sf::Vector2f(-moveSpeed, 0));
    setFacingRight(false);
}

void Player::jump(){
    velocity.y -= 2.50;
    if(isFacingRight()) move(sf::Vector2f(0.5, -2.5));
    else move(sf::Vector2f(-0.5, -2.5));
    setState(CharacterState::STATE_JUMPING);
}

void Player::update(){
    if(dead){
        if(animClock.getElapsedTime().asMilliseconds() >= 1000){
            animClock.restart();
            anim->play("dying");
        }
        return;
    }

    /* Gerencia os botões apertados */
    if(sf::Keyboard::isKeyPressed(key_right)){
        if(velocity.x < maxSlideX)
            velocity.x += 10;
        if(velocity.x > maxSlideX) velocity.x = maxSlideX;
    }else if(sf::Keyboard::isKeyPressed(key_left)){
        if(velocity.x > -maxSlideX)
            velocity.x -= 10;
        if(velocity.x < -maxSlideX) velocity.x = -maxSlideX;
    }else if(sf::Keyboard::isKeyPressed(key_jump) && !collidingUp && collidingDown){
        if(getState() != CharacterState::STATE_JUMPING){
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

    /* Gerencia o estado do jogador */
    if(pSprite.getPosition().y < finalJumpHeight + 15 || collidingLeft || collidingRight){
        setState(CharacterState::STATE_FALLING);
        velocity.y = 0;
    }
    if(getState() == CharacterState::STATE_JUMPING && ( (collidingLeft && !isFacingRight()) || ( collidingRight && isFacingRight()))){
        setState(CharacterState::STATE_FALLING);
        velocity.y = 0;
    }else if(getState() == CharacterState::STATE_JUMPING && collidingUp){
        setState(CharacterState::STATE_FALLING);
        velocity.y = 0;
    }
    if(getState() == CharacterState::STATE_FALLING && collidingDown){
        setState(CharacterState::STATE_IDLE);
        velocity.y = 0;
    }

    /* Gerencia a movimentação do jogador */
    if(velocity.x > 0.001){
        velocity.x -= 1 * std::abs(velocity.x*0.09);
        moveRight();
    }else if(velocity.x < -0.001){
        velocity.x += 1 * std::abs(velocity.x*0.09);
        moveLeft();
    }
    if(velocity.y > 0.001){
        jump();
    }

    /* Gerenciar animações */
    switch (getState()){
        case CharacterState::STATE_WALKING:
            if(animClock.getElapsedTime().asMilliseconds() >= 150){
                animClock.restart();
                anim->play("walk");
                if(!anim->isLocked()){
                    setState(CharacterState::STATE_FALLING);
                }
            }
            if(isFacingRight()){
                anim->setScale(sf::Vector2f(1.f, 1.f));
            }else{
                anim->setScale(sf::Vector2f(-1.f, 1.f));
            }
            break;
        case CharacterState::STATE_JUMPING:
            if(animClock.getElapsedTime().asMilliseconds() >= 50){
                animClock.restart();
                anim->play("jump");
            }
            if(isFacingRight()){
                anim->setScale(sf::Vector2f(1.f, 1.f));
            }else{
                anim->setScale(sf::Vector2f(-1.f, 1.f));
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
                if(isFacingRight())
                    wSprite.setScale(sf::Vector2f(whipSize/range, 1));
                else wSprite.setScale(sf::Vector2f(-whipSize/range, 1));
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

    healthBar.setPosition(sf::Vector2f(getPosition().x-25, getPosition().y+75));
    if(Enemy::enemyCount == 1){
        range = 200;
    }
}

void Player::draw(Engine& engine) const  {
    engine.draw(pSprite);
    if(whipSize > 0) engine.draw(wSprite);
    healthBar.draw(engine);
}

void Player::fall(){
    if(getState() != CharacterState::STATE_JUMPING){
        move(sf::Vector2f(0, 2.50));
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

const sf::Vector2f Player::getPosition() const {
    return pSprite.getPosition();
}

void Player::takeDamage(const float& _damage){
    health -= damage;
    healthBar.setHealth(health);
    move(sf::Vector2f(0, -0.1));
    if(health<=0)
    {
		std::vector<int> sorted;
        std::string buffer, buffer_read;
        std::ifstream ifile("Save/Ranking.txt");

        sorted.push_back(Player::getScore());

        while(ifile.eof())
        {
            ifile>>buffer_read;
            buffer += buffer_read;

            int result;
    		sscanf(buffer_read.c_str(), "%d", &result);
    		sorted.push_back(result);

            std::cout<<buffer_read<<std::endl;
    		//std::cout<<result<<std::endl;
        }
        ifile.close();

        std::ofstream file("Save/Ranking.txt", std::ios_base::app);
        file << buffer << Player::getScore()<< '\n';
        file.close();

        std::sort(sorted.begin(), sorted.end());

        for(int i = 0 ; i<sorted.size();i++)
            std::cout<<sorted[i]<<'\n';

    }
}
