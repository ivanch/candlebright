#include "FallingState.hpp"

FallingState::FallingState(): CharacterState(STATE_FALLING){

}

FallingState::~FallingState(){

}

const bool FallingState::walking(Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new WalkingState());
    return true;
}

const bool FallingState::idle(Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new IdleState());
    return true;
}