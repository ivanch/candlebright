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