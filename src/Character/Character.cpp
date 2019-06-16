#include "Character.hpp"

Character::Character(){
    currentState = nullptr;
}

Character::~Character(){

}

void Character::setState(CharacterState::State newState){
    if(currentState != nullptr){
        if(newState == currentState->getState()) return;
        if(anim->isLocked()) return;
        cout << CharacterState::getStateName(currentState->getState()) << " para " << CharacterState::getStateName(newState) << endl;
        delete currentState;
    }
    switch (newState){
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