#include "Player.hpp"

Player::Player(sf::View& _view, string _name):
        Listener(),
        view(_view), name(_name){

    player.setSize({20,60});
    player.setFillColor(sf::Color::Blue);
    setPos({50.0, 600});
    vida = 100;
    moveSpeed = 1.5;
    jumpHeight = 75;
    maxSlideX = 0.001;
    maxSlideY = 75;
    isJumping = false;
    finalJumpHeight = 0;
    world = NULL;

}
Player::~Player(){}

void Player::move(sf::Vector2f vec){

    player.setPosition({player.getPosition().x + vec.x,
                        player.getPosition().y + vec.y});
    if(player.getPosition().x - (view.getCenter().x+((view.getSize().x)/2))  > -50   && vec.x > 0)
        view.move({vec.x,0});
    if(player.getPosition().x - (view.getCenter().x+((view.getSize().x)/2))  < -550  && vec.x < 0)
        view.move({vec.x,0});
}

void Player::setPos(sf::Vector2f newPos) {
    player.setPosition(newPos);
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
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && world->isColliding(player.getGlobalBounds()) == true){
        if(!isJumping){
            if(velocity.y < maxSlideY)
                velocity.y += jumpHeight;
            if(velocity.y > maxSlideY) velocity.y = maxSlideY;
            finalJumpHeight= (player.getPosition().y) - jumpHeight;

        }
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
    if(player.getPosition().y < finalJumpHeight + 5)
        isJumping=false;
    if(player.getPosition().y > 800)
    {
        vida -= 25;
        sf::Vector2f RespawnPos({50.0,600.0});
        setPos({RespawnPos.x,RespawnPos.y});
        if(vida <= 0)
            std::exit(0);
    }
}


void Player::drawTo(sf::RenderWindow &window) {
    window.draw(player);
}
void Player::fall(){
    if(!isJumping)
        move({0,2.50});
}

sf::FloatRect Player::getRect(){
    return player.getGlobalBounds();
}
