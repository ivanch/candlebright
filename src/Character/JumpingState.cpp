#include "JumpingState.hpp"

JumpingState::JumpingState(): CharacterState(STATE_JUMPING){

}

JumpingState::~JumpingState(){

}

const bool JumpingState::walking(Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new WalkingState());
    return true;
}

const bool JumpingState::falling(Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new FallingState());
    return true;
}