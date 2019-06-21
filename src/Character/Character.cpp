#include "Character.hpp"

Character::Character(){
    currentState = nullptr;
}

Character::~Character(){

}

bool Character::setState(CharacterState::State _newState){
    if(currentState != nullptr){
        if(_newState == currentState->getState()) return true; // Não há necessidade de "renovar" o estado
        if(anim->isLocked()) return false; // Personagem ocupado com uma animação, não sobrepor
        //delete currentState;
    }else{
        currentState = new IdleState();
    }
    switch (_newState){
        case CharacterState::STATE_IDLE:
            return currentState->idle(this);
        case CharacterState::STATE_WALKING:
            return currentState->walking(this);
        case CharacterState::STATE_JUMPING:
            return currentState->jumping(this);
        case CharacterState::STATE_FALLING:
            return currentState->falling(this);
        case CharacterState::STATE_ATTACKING:
            return currentState->attacking(this);
        default:
            return currentState->idle(this);
    }
}

const sf::Vector2f Character::Character::getSize() const {
    return {getRect().width, getRect().height};
}

const float Character::getDamage() const {
    return damage;
}

const float Character::getAttackSpeed() const {
    return attackSpeed;
}

sf::Clock* Character::getAttackClock() {
    return &attackTimer;
}

const float Character::getRange() const {
    return range;
}

const float Character::getHealth() const {
    return health;
}

short Character::getType() {
    return type;
}

short Character::getSubType(){
    return 0;
}

const CharacterState::State Character::getState() {
    return currentState->getState();
}

const CharacterState* Character::getCharacterState() {
    return currentState;
}

void Character::setCharacterState(CharacterState* _newState) {
    currentState = _newState;
}

void Character::setFacing(Facing _facing) {
    facing = _facing;
}

const short Character::getFacing() const {
    return facing;
}

void Character::setHealth(float _health) {
    health = _health;
}