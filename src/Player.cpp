#include "Player.hpp"

Player::Player(sf::View& _view):
        view(_view),pRect({30,60}){

    pRect.setFillColor(sf::Color(255, 63, 63));
    setPos({50.0, 600});
    health = 100;
    moveSpeed = 1.5;
    jumpHeight = 80;
    maxSlideX = 0.001;
    maxSlideY = 80;
    damage = 25.0;
    attackSpeed = 10;
    isJumping = false;
    finalJumpHeight = 0;
}
Player::~Player(){}

void Player::move(sf::Vector2f vec){
    if(vec.x > 0 && ColisionManager::intersectsRightObject(getRect())) return;
    if(vec.x < 0 && ColisionManager::intersectsLeftObject(getRect())) return;
    pRect.move(vec);
    if(pRect.getPosition().x - (view.getCenter().x+((view.getSize().x)/2))  > -50   && vec.x > 0)
        view.move({vec.x,0});
    if(pRect.getPosition().x - (view.getCenter().x+((view.getSize().x)/2))  < -550  && vec.x < 0)
        view.move({vec.x,0});
}

void Player::setPos(sf::Vector2f newPos) {
    pRect.setPosition(newPos);
}

void Player::moveRight(){
    move({moveSpeed,0});
}

void Player::moveLeft(){
    Player::move({-moveSpeed,0});
}

void Player::jump(){
    velocity.y -= 2.50;
    move({0,-2.50});
    isJumping=true;
}

void Player::onUpdate(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if(velocity.x < maxSlideX)
            velocity.x += 10;
        if(velocity.x > maxSlideX) velocity.x = maxSlideX;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if(velocity.x > -maxSlideX)
            velocity.x -= 10;
        if(velocity.x < -maxSlideX) velocity.x = -maxSlideX;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !ColisionManager::intersectsUpObject(getRect()) && ColisionManager::intersectsDownObject((getRect()))){
        if(!isJumping){
            if(velocity.y < maxSlideY)
                velocity.y += jumpHeight;
            if(velocity.y > maxSlideY) velocity.y = maxSlideY;
            finalJumpHeight= (pRect.getPosition().y) - jumpHeight;
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
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
    if(pRect.getPosition().y < finalJumpHeight + 5)
        isJumping=false;
    if(pRect.getPosition().y > 800)
    {
        health -= 25;
        sf::Vector2f RespawnPos({50.0,600.0});
        setPos({RespawnPos.x,RespawnPos.y});
        if(health <= 0)
            std::exit(0);
    }

    if(ColisionManager::intersectsUpObject(getRect()) || ColisionManager::intersectsUpCharacter(getRect())){
        velocity.y = 0;
        isJumping = false;
    }
}

void Player::drawTo(sf::RenderWindow &window) {
    window.draw(pRect);
}

void Player::fall(){
    if(!isJumping){
        move({0,2.50});
    }
}

sf::FloatRect Player::getRect(){
    return pRect.getGlobalBounds();
}

void Player::attack(){
    if(attackTimer.getElapsedTime().asSeconds() < 1/attackSpeed) return;
    for(int i = 0; i < Character::characters.size(); i++){
        if(Character::characters[i] == this) continue;
        if(Distance::getDistance(pRect.getPosition(),Character::characters[i]->getPos()) <= 50.0){
            Character::characters[i]->takeDamage(damage);
        }
    }
    attackTimer.restart();
}

sf::Vector2f Player::getPos(){
    return pRect.getPosition();
}

void Player::takeDamage(float damage){
    health -= damage;
}
