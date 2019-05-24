#include "Player.hpp"

Player::Player(sf::View& _view, string _name):
        view(_view), name(_name){

    setPos({50.0, 600});
    health = 100;
    moveSpeed = 1.5;
    jumpHeight = 80;
    maxSlideX = 0.001;
    maxSlideY = 80;
    damage = 25.0;
    isJumping = false;
    finalJumpHeight = 0;

    if (!pTexture.loadFromFile(_name)){
    cerr << "Erro ao ler arquivo..." << endl;
    }

    pSprite.setTexture(pTexture);
}
Player::~Player(){}

void Player::move(sf::Vector2f vec){
    pSprite.move(vec);
    if(pSprite.getPosition().x - (view.getCenter().x+((view.getSize().x)/2))  > -50   && vec.x > 0)
        view.move({vec.x,0});
    if(pSprite.getPosition().x - (view.getCenter().x+((view.getSize().x)/2))  < -550  && vec.x < 0)
        view.move({vec.x,0});
}

void Player::setPos(sf::Vector2f newPos) {
    pSprite.setPosition(newPos);
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
        if(!Engine::intersectsRight(getRect())){
            if(velocity.x < maxSlideX)
                velocity.x += 10;
            if(velocity.x > maxSlideX) velocity.x = maxSlideX;
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if(!Engine::intersectsLeft(getRect())){
            if(velocity.x > -maxSlideX)
                velocity.x -= 10;
            if(velocity.x < -maxSlideX) velocity.x = -maxSlideX;
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !Engine::intersectsUp(getRect()) && Engine::intersectsDown((getRect()))){
        if(!isJumping){
            if(velocity.y < maxSlideY)
                velocity.y += jumpHeight;
            if(velocity.y > maxSlideY) velocity.y = maxSlideY;
            finalJumpHeight= (pSprite.getPosition().y) - jumpHeight;

        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) debug();
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

    if(Engine::intersectsUp(getRect())){
        velocity.y = 0;
        isJumping = false;
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

void Player::debug(){
    cout << Engine::intersectsUp(getRect()) << ", " << Engine::intersectsDown(getRect()) << ", "
         << Engine::intersectsLeft(getRect()) << ", " << Engine::intersectsRight(getRect()) << ", "
         << isJumping << ", " << endl;
}

void Player::attack(){
    for(int i = 0; i < Enemy::enemies.size(); i++){
        if(Distance::getDistance(pSprite.getPosition(),Enemy::enemies[i]->getPos()) <= 50.0){
            Enemy::enemies[i]->takeDamage(damage);
        }
    }
}
