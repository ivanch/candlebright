#include "Player.hpp"

Player::Player(sf::View& _view):
        view(_view), stand(&pSprite), run(&pSprite){

    setPos({50.0, 600});
    health = 100;
    moveSpeed = 1.5;
    jumpHeight = 80;
    maxSlideX = 0.001;
    maxSlideY = 80;
    damage = 25.0;
    attackSpeed = 2;
    isJumping = false;
    finalJumpHeight = 0;

    isMovingRight = true;
    isMoving = false;

    stand.addAnim("sprites/anim/Stand0.png");
    stand.addAnim("sprites/anim/Stand1.png");
    stand.addAnim("sprites/anim/Stand2.png");
    stand.addAnim("sprites/anim/Stand3.png");
    stand.addAnim("sprites/anim/Stand4.png");
    stand.addAnim("sprites/anim/Stand5.png");

    run.addAnim("sprites/anim/Run0.png");
    run.addAnim("sprites/anim/Run1.png");
    run.addAnim("sprites/anim/Run2.png");
    run.addAnim("sprites/anim/Run3.png");
    run.addAnim("sprites/anim/Run4.png");
    run.addAnim("sprites/anim/Run5.png");
    run.addAnim("sprites/anim/Run6.png");

    stand.setSize({30,65});
    run.setSize({30,65});
}
Player::~Player(){}

void Player::move(sf::Vector2f vec){
    if(vec.x > 0 && ColisionManager::intersectsRight(getRect())) return;
    if(vec.x < 0 && ColisionManager::intersectsLeft(getRect())) return;
    pSprite.move(vec);
    if(pSprite.getPosition().x - (view.getCenter().x+((view.getSize().x)/2))  > -50   && vec.x > 0)
        view.move({vec.x,0});
    if(pSprite.getPosition().x - (view.getCenter().x+((view.getSize().x)/2))  < -550  && vec.x < 0)
        view.move({vec.x,0});
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

void Player::onUpdate(){
    isMoving = false;
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
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !ColisionManager::intersectsUp(getRect()) && ColisionManager::intersectsDown((getRect()))){
        if(!isJumping){
            if(velocity.y < maxSlideY)
                velocity.y += jumpHeight;
            if(velocity.y > maxSlideY) velocity.y = maxSlideY;
            finalJumpHeight= (pSprite.getPosition().y) - jumpHeight;

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

    if(ColisionManager::intersectsUp(getRect())){
        velocity.y = 0;
        isJumping = false;
    }
    if(isMoving){
        if(spriteClock.getElapsedTime().asMilliseconds() >= 250){
            spriteClock.restart();
            run.anim();
        }
        if(isMovingRight){
            run.setScale({1,1});
            stand.setScale({1,1});
        }else{
            run.setScale({-1,1});
            stand.setScale({-1,1});
        }
    }else{
        if(spriteClock.getElapsedTime().asMilliseconds() >= 250){
            spriteClock.restart();
            stand.anim();
        }
    }
}

void Player::drawTo(sf::RenderWindow &window) {
    window.draw(pSprite);
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
    for(int i = 0; i < Character::characters.size(); i++){
        if(Character::characters[i] == this) continue;
        if(Distance::getDistance(pSprite.getPosition(),Character::characters[i]->getPos()) <= 50.0){
            Character::characters[i]->takeDamage(damage);
        }
    }
    attackTimer.restart();
}

sf::Vector2f Player::getPos(){
    return pSprite.getPosition();
}

void Player::takeDamage(float damage){
    health -= damage;
}