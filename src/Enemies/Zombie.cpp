#include "Zombie.hpp"

Zombie::Zombie(sf::Vector2f pos, string _name){
    //eSprite.setSize({20,50});
    //eSprite.setFillColor(sf::Color::Red);
    setPos(pos);
    originalPos = pos;
    moveSpeed = 1.5;
    jumpHeight = 80;
    maxSlideX = 0.001;
    maxSlideY = 80;
    health = 100;
    damage = 5.0;
    range = 10.0;
    attackChance = 0.1 / 60; // Chance de ataques por segundo
    attackSpeed = 0.5;
    finalJumpHeight = 0;
    type = 1;

    setState(CharacterState::STATE_WALKING);
    facing = FACING_RIGHT;

    anim = new AnimManager(&eSprite, {20,50});
    anim->addSheet("walk", "sprites/Zombie/new-zombie-walking.png");
}
Zombie::~Zombie(){}

void Zombie::move(sf::Vector2f vec){
    eSprite.move(vec);
}

void Zombie::setPos(sf::Vector2f newPos) {
    eSprite.setPosition(newPos);
}

sf::Vector2f Zombie::getPos(){
    return eSprite.getPosition();
}

void Zombie::draw(Engine* engine) {
    engine->draw(eSprite);
}

sf::FloatRect Zombie::getRect(){
    return eSprite.getGlobalBounds();
}
void Zombie::fall(){
    if(currentState->getState() != CharacterState::STATE_JUMPING){
        move({0,2.50});
    }
}

void Zombie::moveRight(){
    move({moveSpeed,0});
    setFacing(Facing::FACING_RIGHT);
}

void Zombie::moveLeft(){
    move({-moveSpeed,0});
    setFacing(Facing::FACING_LEFT);
}

void Zombie::update(){
    sf::Vector2f pos = eSprite.getPosition();
    
    if(facing == Facing::FACING_LEFT){
        if(!collidingLeft)
            eSprite.move({-moveSpeed,0});
        else
            facing = Facing::FACING_RIGHT;
        if(abs(pos.x) < abs(originalPos.x-100)) facing = Facing::FACING_RIGHT;
    }else{
        if(!collidingRight)
            eSprite.move({moveSpeed,0});
        else
            facing = Facing::FACING_LEFT;
        if(abs(pos.x) > abs(originalPos.x+100)) facing = Facing::FACING_LEFT;
    }
    if(collidingUp){
        velocity.y = 0;
        setState(CharacterState::STATE_FALLING);
    }

    if(currentState->getState() == CharacterState::STATE_WALKING){
        if(spriteClock.getElapsedTime().asMilliseconds() >= 150){
            spriteClock.restart();
            anim->play("walk");
        }
        if(facing == FACING_RIGHT){
            anim->setScale({-1,1});
        }else{
            anim->setScale({1,1});
        }
    }
    
    if(((float) rand()) / (float) RAND_MAX <= attackChance){
        attack();
    }
}

void Zombie::takeDamage(Thing* issuer, float damage){
    health -= damage;
    move({15,-5});
    moveSpeed += 0.5;
    if(health <= 0){
        cout << "Morreu" << endl;
        //delete this;
    }
}

void Zombie::attack(){
    /*

    // Atacar sem animação é meio tenso. //

    if(attackTimer.getElapsedTime().asSeconds() < 1/attackSpeed) return;
    setState(CharacterState::STATE_ATTACKING);
    attackTimer.restart();
    */
}