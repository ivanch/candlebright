#include "WalkingState.hpp"

WalkingState::WalkingState(): CharacterState(STATE_WALKING){

}

WalkingState::~WalkingState(){

}

const bool WalkingState::idle(Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new IdleState());
    return true;
}

const bool WalkingState::jumping(Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new JumpingState());
    return true;
}

const bool WalkingState::falling(Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new FallingState());
    return true;
}

const bool WalkingState::attacking(Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new AttackingState());
    return true;
}