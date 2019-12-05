#include "RunningState.hpp"

CharacterStates::RunningState::RunningState(): CharacterState(STATE_RUNNING){

}

CharacterStates::RunningState::~RunningState(){

}

const bool CharacterStates::RunningState::idle(Characters::Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new IdleState());
    return true;
}

const bool CharacterStates::RunningState::walk(Characters::Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new WalkingState());
    return true;
}

const bool CharacterStates::RunningState::falling(Characters::Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new FallingState());
    return true;
}