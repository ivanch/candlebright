#include "Character.hpp"

Character::Character(){
    currentState = nullptr;
}

Character::~Character(){

}

void Character::setState(CharacterState::State _state){
    if(currentState != nullptr){
        if(_state == currentState->getState()) return;
        delete currentState;
    }
    switch (_state){
        case CharacterState::STATE_IDLE:
            currentState = new IdleState();
            break;
        case CharacterState::STATE_WALKING:
            currentState = new WalkingState();
            break;
        case CharacterState::STATE_JUMPING:
            currentState = new JumpingState();
            break;
        case CharacterState::STATE_FALLING:
            currentState = new FallingState();
            break;
        case CharacterState::STATE_ATTACKING:
            currentState = new AttackingState();
            break;
        default:
            currentState = new IdleState();
            break;
    }
}