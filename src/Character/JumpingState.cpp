#include "JumpingState.hpp"

JumpingState::JumpingState(): CharacterState(STATE_JUMPING){

}

JumpingState::~JumpingState(){

}

bool JumpingState::falling(Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new FallingState());
    return true;
}