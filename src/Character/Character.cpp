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
        return true;
    }
    switch (_newState){
        case CharacterState::STATE_IDLE:
            //currentState = new IdleState();
            return currentState->idle(this);
        case CharacterState::STATE_WALKING:
            //currentState = new WalkingState();
            return currentState->walking(this);
        case CharacterState::STATE_JUMPING:
            //currentState = new JumpingState();
            return currentState->jumping(this);
        case CharacterState::STATE_FALLING:
            //currentState = new FallingState();
            return currentState->falling(this);
        case CharacterState::STATE_ATTACKING:
            //currentState = new AttackingState();
            return currentState->attacking(this);
        default:
            //currentState = new IdleState();
            return currentState->idle(this);
    }
}